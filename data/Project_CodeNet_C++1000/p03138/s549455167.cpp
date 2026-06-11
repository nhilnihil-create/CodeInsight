#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,P>
using namespace std;
 
 
int main(){
    int n; cin >> n;
    ll k; cin >> k;
    ll K=k;
    int keta=0;
    string ks="";
    while(K){
        if(K%2==0) ks+='0';
        else ks+='1';
        K/=2;
        keta++;
    }
 
    int  b[41][2];
    rep(i,40)rep(j,2) b[i+1][j]=0;
    rep(i,n){
        ll a; cin >> a;
        rep(j,40){
            if(a%2==0) b[j+1][0]++;
            else b[j+1][1]++;
            a/=2;
        }
    }
    ll dp[41][2];
    if(k!=0){
        dp[keta][0]=b[keta][1]*pow(2,keta-1);
        dp[keta][1]=b[keta][0]*pow(2,keta-1);
        //cout << dp[keta][0] << ' ' << dp[keta][1] << endl;
        for(int j=keta-1; j>0; j--){
            ll ad=(ll)pow(2,j-1);
            if(ks[j-1]=='1'){
                dp[j][0]=max(dp[j+1][0]+max(b[j][0],b[j][1])*ad,dp[j+1][1]+b[j][1]*ad);
                dp[j][1]=dp[j+1][1]+b[j][0]*ad;
            }
            else{
                dp[j][0]=dp[j+1][0]+max(b[j][0],b[j][1])*ad;
                dp[j][1]=dp[j+1][1]+b[j][1]*ad;
            }
        }
    }
    else{
        dp[1][0]=dp[1][1]=0;
    }
    ll ans=0;
    for(int i=40; i>keta; i--){
        ans+=b[i][1]*pow(2,i-1);
    }
    cout << max(dp[1][0],dp[1][1])+ans << endl;
return 0;
}