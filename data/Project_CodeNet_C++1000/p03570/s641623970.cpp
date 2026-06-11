#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    unordered_map<int,int> mp,used;
    used[0]=1;
    mp[0]=0;
    int now=0;
    rep(i,0,s.size()){
        int t=s[i]-'a';
        now^=(1<<t);
        if(now==0)continue;
      int u=1000000000;
      if(used[now]==1)u=mp[now];
        used[now]=1;
        int mi=1000000000;
        rep(j,0,26){
            int y=1<<j;
           // if((now&y)!=y)continue;
            int r=now^y;
            if(used[r]==0)continue;
            mi=min(mi,mp[r]);
        }
      
        mp[now]=min(u,mi+1);
    }
    mp[0]=1;
    cout<<mp[now]<<endl;
}
