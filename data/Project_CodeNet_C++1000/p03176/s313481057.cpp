//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};

//最大値更新
const ll MAX_N=114514*2;
ll bit[MAX_N],n;
//1-indexed (i=0で抜けれるようにするため)
ll query(ll i){
    ll s=0;
    while(i>0){
        s=max(s,bit[i]);
        i-=i&-i;
    }
    return s;
}

void upd(ll i,ll x){
    while(i<=n){
        bit[i]=max(bit[i],x);
        i+=i&-i;
    }
}
int main(){
    cin>>n;
    vl h(n);
    rep(i,n){
        cin>>h[i];
    }
    vl a(n);
    rep(i,n)cin>>a[i];
    rep(i,n){
        upd(h[i],query(h[i])+a[i]);
    }
    cout<<query(n)<<endl;
}
    