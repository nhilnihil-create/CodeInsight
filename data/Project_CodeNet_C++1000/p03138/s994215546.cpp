#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fr first
#define sc second
const int mod = 1e9+7;
const int N = 1e6+6;
ll a[N];
int main(){
    int n;
    ll k ;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    ll lst = 0;
    ll trt = 0;
    for(ll j=50;j>=0;j--){
        int cnt0 = 0;
        int cnt1 = 0;
        for(int i=1;i<=n;i++){
            if(a[i]&(1ll<<j))cnt1++;
            else cnt0++;
        }
        int idk = 0;
        if(k&(1ll<<j))idk =1 ;
        if(idk==1){
            if(cnt0==cnt1){
                lst = 1;
            }
            else if(cnt0>cnt1){
               trt+=(1ll<<j);
            }
            else if(cnt1>cnt0){
                lst = 1;
            }
        }
        else{
            if(cnt0==cnt1){
                /// do nothing
            }
            else if(cnt0>cnt1){
                if(lst){
                    trt+=(1ll<<j);
                }
            }
            else if(cnt1>cnt0){
                /// do nothing
            }

        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans+=(trt^a[i]);
    }
    cout<<ans<<endl;
}
