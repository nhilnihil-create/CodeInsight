#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
typedef long long ll;
const ll mod=1e9+7;
int main(){
    ll n,q;cin>>n>>q;
    string s;cin>>s;
    vector<char>t(q),d(q);
    rep(i,q)cin>>t[i]>>d[i];
    ll ans=n;
    ll now=0;
    rep(i,q){
        if(t[i]==s[now]){
            if(d[i]=='R')now++;
            else now--;
        }
        if(now<0)break;
        if(now>=n)break;
    }
    if(now<0){
        ll l=0,r=n;
        while(r-l>1){
            ll k=(r+l)/2;
            ll im=k;
            rep(i,q){
                if(t[i]==s[im]){
                    if(d[i]=='R')im++;
                    else im--;
                }
                if(im<0)break;
                if(im>=n)break;
            }
            if(im<0)l=k;
            else r=k;
        }
        ans-=l+1;
    }
    now=n-1;
    rep(i,q){
        if(t[i]==s[now]){
            if(d[i]=='R')now++;
            else now--;
        }
        if(now<0)break;
        if(now>=n)break;
    }
    if(now>=n){
        ll l=-1,r=n-1;
        while(r-l>1){
            ll k=(r+l)/2;
            ll im=k;
            rep(i,q){
                if(t[i]==s[im]){
                    if(d[i]=='R')im++;
                    else im--;
                }
                if(im<0)break;
                if(im>=n)break;
            }
            if(im>=n)r=k;
            else l=k;
        }
        ans-=n-r;
    }
    cout<<ans<<endl;
}
