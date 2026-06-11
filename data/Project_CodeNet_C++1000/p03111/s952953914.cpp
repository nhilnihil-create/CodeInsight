#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int N, A, B, C;
vector<int> lens;

int dfs(int cur, int a, int b, int c) {
    if(cur == N) {
        if(a == 0 || b == 0 || c == 0) {
            return 1 << 29;
        } else {
            return abs(A - a) + abs(B - b) + abs(C - c);
        }
    } else {
        int res1 = dfs(cur + 1, a + lens[cur], b, c);
        if(a != 0) res1 += 10;

        int res2 = dfs(cur + 1, a, b + lens[cur], c);
        if(b != 0) res2 += 10;

        int res3 = dfs(cur + 1, a, b, c + lens[cur]);
        if(c != 0) res3 += 10;

        int res4 = dfs(cur + 1, a, b, c);

        return min({res1, res2, res3, res4});
    }
}

int main() {
    cin >> N >> A >> B >> C;
    REP(i, N) {
        int tmp;
        cin >> tmp;
        lens.emplace_back(tmp);
    }
    cout << dfs(0, 0, 0, 0) << endl;
    return 0;
}