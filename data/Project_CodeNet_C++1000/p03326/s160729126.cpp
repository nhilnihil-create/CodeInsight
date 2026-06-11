#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    ll n,m;cin>>n>>m;
    vll p(n),q(n),r(n),s(n);
    ll x,y,z;
    rep(i,n){
        cin>>x>>y>>z;
        p[i]=x+y+z;
        q[i]=-x+y+z;
        r[i]=x-y+z;
        s[i]=x+y-z;
    }
    sort(all(p));
    sort(all(q));
    sort(all(r));
    sort(all(s));
    ll ans=0;ll front=0;ll back=0;
    rep(i,m){
        front+=p[i];
        back+=p[n-1-i];
    }
    ans=max(ans,max(abs(front),abs(back)));
    front=0;back=0;
    rep(i,m){
        front+=q[i];
        back+=q[n-1-i];
    }
    ans=max(ans,max(abs(front),abs(back)));
    front=0;back=0;
    rep(i,m){
        front+=r[i];
        back+=r[n-1-i];
    }
    ans=max(ans,max(abs(front),abs(back)));
    front=0;back=0;
    rep(i,m){
        front+=s[i];
        back+=s[n-1-i];
    }
    ans=max(ans,max(abs(front),abs(back)));
    cout<<ans<<endl;
}