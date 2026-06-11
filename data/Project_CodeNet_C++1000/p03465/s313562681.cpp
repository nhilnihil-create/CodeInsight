#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2001, C = N * N;
bitset <C> dp;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    dp[0] = 1;
    int n; cin >> n;
    int sum = 0;
    while (n--) {
        int x; cin >> x;
        sum += x;
        dp |= dp << x;
    }   
    for (int i = (sum + 1) >> 1; ; ++i) {
        if (dp[i]) {
            cout << i << '\n';
            exit(0);
        }   
    }   
}   