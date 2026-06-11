#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    ll x;
//    x=1ll << 59;
//    ll y=(1ll << 59) - 1ll;
//    cout<<((double)(x)==(double)(x-1))<<endl;
    ll n,y;
    cin>>n>>y;
    //for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                    ll i=n-j-k;
                ll s=10000ll*i+5000ll*j+1000ll*k;
                if(s==y&&(i+j+k)==n&&i>=0){
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    return 0;
                }
                //                  cout<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    //}
    cout<<"-1 -1 -1";
}
