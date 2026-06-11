#include <bits/stdc++.h>

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
    int N, K;
    cin >> N >> K;
    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }

    int ans = 0;
    for (int x = 0; x <= min(N, K); ++x) {
        for (int y = 0; x + y <= min(N, K); ++y) {
            multiset<int, greater<int>> S;
            for (int i = 0; i < x; ++i) {
                S.insert(V[i]);
            }
            for (int i = 0; i < y; ++i) {
                S.insert(V[N-i-1]);
            }

            int sum = 0;
            int res = x + y;
            for (int item : S) {
                if (item < 0 && res <= K - (x + y)) {
                    break;
                }
                res -= 1;
                sum += item;
            }
            ans = max(ans, sum);
            // print(x, y, sum);
        }
    }

    cout << ans << endl;
       
    return 0;
}
