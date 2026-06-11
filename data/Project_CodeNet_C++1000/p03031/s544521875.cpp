#include <iostream>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
 
int main(){
    ll n,m,count,cnt,ans=0;
    
    cin>>n>>m;
  int s[11][11],p[11],k[11];
    rep(i,m){
        cin>>k[i];
        rep(j,k[i]){
            cin>>s[i][j];
        }
    }
    rep(i,m){
        cin>>p[i];
    }
    rep(bit,(1<<n)){
        cnt=0;
        rep(i,m){
            count=0;
            rep(j,k[i]){
                if(bit&(1<<(s[i][j]-1))){
                    count++;
                }
            }
            if(count%2==p[i]){
                cnt++;
            }
        }
        if(cnt==m){
            ans++;
        }
    }
    cout<<ans;
}