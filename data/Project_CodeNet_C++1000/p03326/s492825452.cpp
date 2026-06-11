#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <queue>
#include <iomanip>
#include <iterator>

#define MOD 1000000007
#define INF 1000000001

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


template <class T>
ostream &operator<<(ostream &o, const vector<T>&obj) {
    o << "["; for (int i = 0; i < (int)obj.size(); ++i) o << (i > 0 ? ", " : "") << obj[i]; o << "]"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const pair<T, U>&obj) {
    o << "(" << obj.first << ", " << obj.second << ")"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const map<T, U>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const set<T>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const queue<T>&obj) {
    queue<T> obj_cp = obj;
    bool first = true;
    o << "{";
    while (!obj_cp.empty()) { o << (!first ? ", " : "") << obj_cp.front(); obj_cp.pop(); first = false; }
    o << "}"; return o;
}

void print() {
    cout << "\n";
}
template<class Head, class... Body>
void print(Head head, Body... body) {
    cout << head << " ";
    print(body...);
}


int main(int argc, char const *argv[]) {
    int N, M;
    cin >> N >> M;
    vector<ll> x(N), y(N), z(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }

    vector<int> idxs(N);
    for (int i = 0; i < N; ++i) {
        idxs[i] = i;
    }

    ll ans = 0;
    for (int s = 0; s < 8; ++s) {
        int sx = ((s >> 0) & 1) * 2 - 1;
        int sy = ((s >> 1) & 1) * 2 - 1;
        int sz = ((s >> 2) & 1) * 2 - 1;
        sort(idxs.begin(), idxs.end(), [&](int a, int b) {
            return x[a]*sx + y[a]*sy + z[a]*sz > x[b]*sx + y[b]*sy + z[b]*sz;
        });
        ll sum = 0;
        for (int i = 0; i < M; ++i) {
            sum += x[idxs[i]]*sx + y[idxs[i]]*sy + z[idxs[i]]*sz;
        }
        if (ans < sum) {
            ans = sum;
        }
        // print(s, sx, sy, sz, sum);
    }

    cout << ans << endl;

    return 0;
}
