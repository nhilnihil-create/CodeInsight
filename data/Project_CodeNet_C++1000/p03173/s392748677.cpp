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
    vector<int> arr(n);
    vector<int> presum(n);
    int refix = 0;
    for (int i = 0 ; i < n; i++) {
        cin>>arr[i];
        refix += arr[i];
        presum[i] = refix;
    }
    trb(L,n-1,0){
        tr(R,L,n-1){
            if (L==R) {
                dp[L][R] = 0;
            } else {
                dp[L][R] = 1e18;
                for (int i = L ; i < R  ; i++) {
                    dp[L][R] = min(dp[L][R], dp[L][i] + dp[i+1][R] + presum[R] - (L==0 ? 0 : presum[L-1]));
                }
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}

