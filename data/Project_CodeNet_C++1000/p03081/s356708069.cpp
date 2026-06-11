#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll n,q;
string s;
vector<char> t,d;

int f(ll x){
    if(x<0)return -1;
    if(n<=x)return 1;
    rep(i,q){
        if(t[i]==s[x]){
            x+=(d[i]=='R'?1:-1);
        }
        if(x==-1)return -1;
        if(x==n)return 1;
    }
    return 0;
}

int main(){
    cin>>n>>q>>s;
    t.resize(q);
    d.resize(q);
    rep(i,q)cin>>t[i]>>d[i];
    ll l=-1,r=n;
    while(l<r-1){
        ll mid=(r+l)/2;
        if(f(mid)==-1)l=mid;
        else r=mid;
    }
    ll num=r;
    l=-1; r=n;
    while(l+1<r){
        ll mid=(l+r)/2;
        if(f(mid)==1)r=mid;
        else l=mid;
    }
    cout<<r-num<<endl;
}