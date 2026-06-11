#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n))
typedef bitset<21> MASK;

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}
ll n,arr[22][22],dp[22][1<<21],mod=1e9+7;;

ll ans(int i,MASK mask){
//    cout<<i<<" ";
    if(i==n)return 1;
   ll &res=dp[i][mask.to_ulong()];
   if(~res)return res;
     res=0;
    for (int j = 0; j <n ; ++j) {
        if(arr[i][j]&&mask[j]){
            MASK t=mask;
            t[j]=0;
            res+=ans(i+1,t)%mod;
            res%=mod;
        }
    }
    return res;
}


int main() {
    fast();
    clr(dp,-1);
    MASK m;
    m.flip();
//    cout<<m.to_string();
    cin>>n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <n ; ++j) {
            cin>>arr[i][j];
        }
    }
    cout<<ans(0,m);


}
