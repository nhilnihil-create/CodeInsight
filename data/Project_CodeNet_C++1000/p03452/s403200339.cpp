#define _GLIBCXX_DEBUG
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

vin par(100010);
vin deep(100010);
vin wei(100010);
void init(int n);
int root(int x);
void unite(int x,int y,int w);
bool same(int x,int y);
int weight (int x);
int diff(int x,int y);

int main(){
    int n,m;cin>>n>>m;
    vin l(m),r(m),d(m);
    rep(i,m)cin>>l[i]>>r[i]>>d[i];
    init(n);
    bool can=true;
    rep(i,m){
        if(same(l[i],r[i])&&diff(l[i],r[i])!=d[i]){
            can=false;
            break;
        }
        unite(l[i],r[i],d[i]);
    }
    if(can)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

void init(int n){
    rep(i,n){
        par[i]=i;
        deep[i]=0;
        wei[i]=0;
    }
}
int root(int x){
    if(par[x]==x)return x;
    else{
        int r=root(par[x]);
        wei[x]+=wei[par[x]];
        return par[x]=r;
    }
}
void unite(int x,int y,int w){
    w+=weight(x);w-=weight(y);
    x=root(x);
    y=root(y);
    if(x==y)return;
    if(deep[x]<deep[y]){
        swap(x,y);
        w=-w;
    }
    if(deep[x]==deep[y])deep[x]++;
    par[y]=x;
    wei[y]=w;
}
bool same(int x,int y){
    return root(x)==root(y);
}
int weight(int x){
    root(x);
    return wei[x];
}
int diff(int x,int y){
    return weight(y)-weight(x);
}