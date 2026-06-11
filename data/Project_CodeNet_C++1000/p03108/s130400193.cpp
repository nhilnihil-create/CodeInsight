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
const ll inf=1e9+7;
const ll INF=1e18;

vin par(100050);
vin deep(100050);
vin sizee(100050);
void init(int n);
int root(int x);
void unite(int x,int y);
bool same(int x,int y);

int main(){
    ll n,m;cin>>n>>m;
    vll a(m),b(m);
    rep(i,m)cin>>a[i]>>b[i];
    ll ans=n*(n-1)/2;
    reverse(all(a));reverse(all(b));
    stack<ll> s;s.push(ans);
    init(n);
    ll tmpa,tmpb;
    rep(i,m-1){
        if(same(a[i],b[i]))unite(a[i],b[i]);
        else{
            tmpa=sizee[root(a[i])];
            tmpb=sizee[root(b[i])];
            ans+=tmpa*(tmpa-1)/2+tmpb*(tmpb-1)/2;
            unite(a[i],b[i]);
            ans-=(tmpa+tmpb)*(tmpa+tmpb-1)/2;
        }
        s.push(ans);
    }
    while(s.size()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void init(int n){
    rep(i,n+1){
        par[i]=i;
        deep[i]=0;
        sizee[i]=1;
    }
}
int root(int x){
    if(par[x]==x)return x;
    else return par[x]=root(par[x]);
}
void unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return;
    if(deep[x]<deep[y]){
        par[x]=y;
        sizee[y]+=sizee[x];
    }
    else{
        par[y]=x;
        sizee[x]+=sizee[y];
        if(deep[x]==deep[y])deep[x]++;
    }
}
bool same(int x,int y){
    return root(x)==root(y);
}