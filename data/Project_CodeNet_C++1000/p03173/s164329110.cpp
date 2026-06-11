#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll INF=1e18L+5;
const int nax=405;
ll dp[nax][nax];
int main()
{
    int n;cin>>n;
    vector<long long int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    auto sum=[&](int L,int R){
        ll ans=0;
         for(int i=L;i<=R;i++) ans+=v[i];
         return ans;
    };

      for(int L=n-1;L>=0;L--){
        for(int R=L;R<n;R++){
            if(L==R){
                dp[L][R]=0;
            }
           else {
                dp[L][R]=INF;
                ll s=sum(L,R);
              for(int i=L;i<R;i++){
                dp[L][R]=min(dp[L][R],dp[L][i]+dp[i+1][R]+s);
              }
           }
        }
      }
     cout<<dp[0][n-1];

}
