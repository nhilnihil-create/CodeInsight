#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,k,a[N];
ll func(ll bit,ll flg){
    if(bit==-1)return 0;
    if(flg){
        ll cnt = 0 ;
        for(ll i=1;i<=n;i++)cnt+=(a[i]>>bit)%2;
        ll ans = (1ll<<bit) * max(cnt , n - cnt);
        return ans + func(bit-1,flg);
    }
    else{
        ll cnt = 0;
        for(ll i=0;i<=n;i++)cnt+=(a[i]>>bit)%2;
        if((k>>bit)&1){
            if(cnt>=n-cnt){
                ll ans = (1ll<<bit)*cnt;
                return ans + func(bit-1,1);
            }
            else{
                ll ans = (1ll<<bit)*(n-cnt);
                return ans + func(bit-1,0);
            }
        }
        else{
            ll ans = (1ll<<bit)*cnt;
            return ans + func(bit-1,flg);
        }
    }
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>a[i];
    cout<<func(61,0);
}