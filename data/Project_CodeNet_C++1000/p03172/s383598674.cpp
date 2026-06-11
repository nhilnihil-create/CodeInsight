#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define test ll t; cin>>t; while(t--)
typedef long long int ll;
void add_self(ll &x,ll y){
    x+=y;
    if(x>=mod){
        x%=mod;
    }
}
int main() {
    FIO;
    //test
    {
        ll n,k,x;
        cin>>n>>k;
        vector<ll>prefix(k+1),dp(k+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            cin>>x;
            for(int j=0;j<=k;j++){
                prefix[j]=0;
            }
            // We will be dealing with states
            for(int j=0;j<k;j++){
                prefix[j+1]+=dp[j];
                if(j+x+1<=k){
                    prefix[j+x+1]-=dp[j];
                }
            }
            for(int j=1;j<=k;j++){
                prefix[j]+=prefix[j-1];
            }
            for(int j=0;j<=k;j++){
                add_self(dp[j],prefix[j]);
            }
        }
        cout<<dp[k]<<endl;
    }
	return 0;
}
