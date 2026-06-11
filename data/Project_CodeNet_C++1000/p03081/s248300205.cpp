#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
string s;
char t[N],d[N];
ll n,q;
ll chk(ll p){
    for(ll i=1;i<=q;i++){
        if(t[i]==s[p]){
            if(d[i]=='L')p--;
            else p++;
            if(p<0 || p>=n)return p;
        }
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q>>s;
    for(ll i=1;i<=q;i++)cin>>t[i]>>d[i];
    ll ans = n;
    ll s=0,e=n-1;
    while(s<=e){
        ll mid=(s+e)>>1;
        if(chk(mid)<0)s=mid+1;
        else e=mid-1;
    }
    ans-=s;
    s=0,e=n-1;
    while(s<=e){
        ll mid=(s+e)>>1;
        if(chk(mid)>=n)e=mid-1;
        else s=mid+1;
    }
    ans-=(n-1-e);
    cout<<ans;
}