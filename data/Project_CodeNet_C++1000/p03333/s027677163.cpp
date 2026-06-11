#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
using pp=pair<P,int>;
int main(){
  int n;
  cin>>n;
  V<bool> used(n,false);
  priority_queue<pp,V<pp>,greater<pp>> l,tmpl;
  priority_queue<pp> r,tmpr;
  for(int i=0;i<n;i++){
    P a;
    cin>>a.fi>>a.se;
    r.emplace(a,i);
    tmpr.emplace(a,i);
    swap(a.fi,a.se);
    l.emplace(a,i);
    tmpl.emplace(a,i);
  }
  ll ans=0,bfo=0;
  while(l.size()&&r.size()){
    while(l.size()){
        pp p=l.top();
        l.pop();
        if(used[p.se])continue;
        used[p.se]=1;
        if(p.fi.se<=bfo&&bfo<=p.fi.fi)break;
        if(p.fi.fi<=bfo&&bfo<=p.fi.se)break;
        ans+=min(abs(bfo-p.fi.fi),abs(bfo-p.fi.se));
        bfo=p.fi.fi;
        break;
    }
    while(r.size()){
        pp p=r.top();
        r.pop();
        if(used[p.se])continue;
        used[p.se]=1;
        if(p.fi.se<=bfo&&bfo<=p.fi.fi)break;
        if(p.fi.fi<=bfo&&bfo<=p.fi.se)break;
         ans+=min(abs(bfo-p.fi.fi),abs(bfo-p.fi.se));
        bfo=p.fi.fi;
        break;
    }
  }
   ans+=abs(bfo);
   ll res=0;
   while(tmpl.size()){
     l.push(tmpl.top());
     tmpl.pop();
   }
      while(tmpr.size()){
     r.push(tmpr.top());
     tmpr.pop();
   }
   bfo=0;
   used.assign(n,false);
     while(l.size()&&r.size()){
    while(r.size()){
        pp p=r.top();
        r.pop();
        if(used[p.se])continue;
        used[p.se]=1;
        if(p.fi.se<=bfo&&bfo<=p.fi.fi)break;
        if(p.fi.fi<=bfo&&bfo<=p.fi.se)break;
        res+=min(abs(bfo-p.fi.fi),abs(bfo-p.fi.se));
        bfo=p.fi.fi;
        break;
    }
    while(l.size()){
        pp p=l.top();
        l.pop();
        if(used[p.se])continue;
        used[p.se]=1;
        if(p.fi.fi<=bfo&&bfo<=p.fi.se)break;
        if(p.fi.se<=bfo&&bfo<=p.fi.fi)break;
         res+=min(abs(bfo-p.fi.fi),abs(bfo-p.fi.se));
        bfo=p.fi.fi;
        break;
    }
  }
  chmax(ans,res+abs(bfo));
   cout<<ans<<"\n";
}