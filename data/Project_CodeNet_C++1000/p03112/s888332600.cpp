#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
#include <iomanip>
#include <deque>
#include <queue>
#include <unordered_map>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <sstream>
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll pow(ll N, ll P){
    if(P==0) return 1;
    if(P%2==0){
        ll t = pow(N, P/2);
        return t*t;
    }
    return N * pow(N, P-1);
}
ll modpow(ll N, ll P,ll k){
    if(P==0) return 1;
    if(P%2==0){
        ll t = modpow(N, P/2,k)%k;
        return t*t%k;
    }
    return N * modpow(N, P-1,k)%k;
}
ll modkai(ll n,ll m,ll k){//n*(n-1)*(n-2)*...(m+1)%k
    if(n == m)return 1;
    return modkai(n-1,m,k)*n%k;
}
ll mod_cnb(ll n,ll m,ll k){//nCm%k,kは十分大きい素数
  int m_=modkai(m,0,k);
  return modkai(n,n-m,k)*modpow(m_,k-2,k)%k;
}
ll gcd(ll n,ll m){
    ll n_ = max(n,m);
    ll m_ = min(n,m);
    if(n_%m_ == 0)return m_;
    return gcd(m_,n_%m_);
}
ll lcm(ll n,ll m){
    return n*m/gcd(n,m);
}

int main() {
   ll a,b,q;cin>>a>>b>>q;
   vector<ll>s(a),t(b),x(q);
   rep(i,a)cin>>s[i];
   rep(i,b)cin>>t[i];
   rep(i,q)cin>>x[i];
   vector<ll>ans(q);
   rep(i,q){
       ans[i]=1e11;
       auto sh=lower_bound(s.begin(),s.end(),x[i]);
       auto te=lower_bound(t.begin(),t.end(),x[i]);
       ll ft,bt,fs,bs;
       bool flag[4];
       rep(j,4)flag[j]=1;
       if(sh==s.begin()){flag[0]=0;fs=-1e12;}
       if(te==t.begin()){flag[1]=0;ft=-1e12;}
       if(sh==s.end()){flag[2]=0;bs=1e12;}
       if(te==t.end()){flag[3]=0;bt=1e12;}
       if(flag[2])bs=*sh;
       if(flag[3])bt=*te;
       if(flag[0]){sh--;fs=*sh;}
       if(flag[1]){te--;ft=*te;}
       ans[i]=min(ans[i],max(bs,bt)-x[i]);
       ans[i]=min(ans[i],x[i]-min(fs,ft));
       ans[i]=min(ans[i],min(x[i]-fs,bt-x[i])+bt-fs);
       ans[i]=min(ans[i],min(bs-x[i],x[i]-ft)+bs-ft);
       
   }
rep(i,q)cout<<ans[i]<<endl;
}