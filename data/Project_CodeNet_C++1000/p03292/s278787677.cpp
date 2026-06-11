#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    int ans = 1e9;
    ans = min(ans, abs(a2-a1)+abs(a3-a2));
    ans = min(ans, abs(a3-a1)+abs(a2-a3));
    ans = min(ans, abs(a1-a2)+abs(a3-a1));
    ans = min(ans, abs(a3-a2)+abs(a1-a3));
    ans = min(ans, abs(a1-a3)+abs(a2-a1));
    ans = min(ans, abs(a2-a3)+abs(a1-a2));

    cout << ans << endl;
    
    return 0;
}
