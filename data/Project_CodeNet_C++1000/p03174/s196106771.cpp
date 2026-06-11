#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define int long long int
#define vi vector<int>
#define vvi vector < vi >
#define pii pair<int,int>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define tr(k,st,en) for(int k = st; k <= en ; ++k)
#define trb(k,en,st) for(int k = en; k >= st ; --k)
using namespace std;

// n* k^k

void add_self(int& a, int b){
    a+=b;
    if (a >= mod) {
        a -= mod;
    }
    if (a < 0) {
        a += mod;
    }
}

int dp[402][402];

int32_t main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<vector<int>> can(n,vector<int>(n));
    tr(i,0, n-1){
        tr(j,0,n-1){
            cin>>can[i][j];
        }
    }
    int sz = 1ll<<n;
    vector<int> dp(sz);
    dp[0] = 1;
    tr(mask,0,sz - 2){
        int men = (int)__builtin_popcount(mask);
        tr(women,0,n-1){
            if (can[men][women] && !(mask & (1ll<<women))) {
                int newmask = mask^(1ll<<women);
                dp[newmask] = (dp[newmask] + dp[mask])%mod;
            }
        }
    }
    cout<<dp[sz-1]<<endl;
}

