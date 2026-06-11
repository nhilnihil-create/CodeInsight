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
    int N;
    cin >> N;
    vector<int> D(N);
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }
    sort(D.begin(), D.end());
    // print(D);

    vector<int> hours = {0};
    for (int i = 0; i < N; ++i) {
        int d = (i % 2 == 0) ? D[i] : 24 - D[i];
        hours.push_back(d);
    }

    sort(hours.begin(), hours.end());
    // print(hours);

    int ans = 24;
    for (int i = 0; i < N+1; ++i) {
        int d = abs(hours[(i+1)%(N+1)] - hours[i]);
        ans = min(ans, min(d, 24 - d));
        // print(i, (i+1)%N, min(d, 24 - d), ans);
    }
    cout << ans << endl;

    return 0;
}
