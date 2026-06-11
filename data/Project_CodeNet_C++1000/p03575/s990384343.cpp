#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m;
ll a[55],b[55],d[55][55];
ll ans;
int main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                d[j][k]=1000000000000000;
                if(j==k){
                    d[j][k]=0;
                }
            }
        }
        for(int j=0;j<m;j++){
            if(j!=i){
                d[a[j]-1][b[j]-1]=1;
                d[b[j]-1][a[j]-1]=1;
            }
        }
        for(int l=0;l<n;l++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    d[j][k]=min(d[j][k],d[j][l]+d[l][k]);
                }
            }
        }
        bool x=false;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(d[j][k]>=1000000000000000){
                    x=true;
                }
            }
        }
        if(x){
            ans++;
        }
    }
    cout<<ans<<endl;

}
