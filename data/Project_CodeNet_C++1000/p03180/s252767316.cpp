#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define sz() size()
#define fr first
#define sc second
#define int long long
#define mp make_pair
#define rc(s) return cout<<s,0
#define rcc(s) cout<<s,exit(0)
using namespace std;

int n;

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> cost[i][j];
        }
    }
    // O(2^n * n * n ~ 2 * 10^7)
    vector<int> precalc(1 << n);
    for(int i=0;i<(1 << n);i++){
        for(int j=0;j<n;j++){
            for(int t=j+1;t<n;t++){
                if(i & (1 << j) && i & (1 << t)) precalc[i] += cost[j][t];
            }
        }
    }
    // O(3^n) ~ 4 * 10^7
    vector<int> dp((1 << n));
    for(int i=1;i<(1 << n);i++){
        for(int j=i;j!=0;j=(j-1)&i){
            dp[i] = max(dp[i], dp[i ^ j] + precalc[j]);
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}
