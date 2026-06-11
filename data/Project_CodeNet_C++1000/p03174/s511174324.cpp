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

const int mod = 1e9 + 7;

int n;

void add(int &a, int b){
    a += b;
    if(a >= mod){
        a = a - mod;
    }
}

int32_t main(){
   // ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    vector<vector<int>>can(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> can[i][j];
    vector<int>dp((1 << n));

    dp[0] = 1;

    for(int i=1;i<(1<<n);i++){
        int curr = __builtin_popcount(i);
        for(int j=0;j<n;j++){
            if(i & (1 << j) && can[curr - 1][j] == 1){
                add(dp[i],dp[i ^ (1 << j)]);
            }
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}
