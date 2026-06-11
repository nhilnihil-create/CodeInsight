#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,x); REP(i,sizeof(a)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}

#define pll pair<ll,ll>


int main(){
  ll N,K; cin>>N>>K;
  priority_queue<pll> q;
  priority_queue<pll, vector<pll>, greater<pll> > r;
  umap<ll,ll> exist_neta;
  
  REP(count,N){
    ll t,d; cin>>t>>d;
    q.push(make_pair(d,t));
  }
  ll num_neta = 0;
  ll oishisa_base = 0;
  ll oishisa_max;
  REP(count,K){
    oishisa_base += q.top().first;
    ll t = q.top().second;
    ++exist_neta[t];
    if(exist_neta[t]==1){
      ++num_neta;
    }
    r.push(q.top());
    q.pop();
  }
  oishisa_max = oishisa_base + num_neta*num_neta;
  
  while(1){
    bool ok = false;
    // 食べる集合のうち取り出せるものを探す
    while(!r.empty()){
      if( exist_neta[r.top().second]>1 ){
        oishisa_base -= r.top().first;
        --exist_neta[r.top().second];
        r.pop();
        ok = true;
        break;
      }else{
        r.pop();
      }
    }
    if(!ok){break;}
    // 食べない集合のうち新種を探す
    while(!q.empty()){
      if( exist_neta[q.top().second]==0 ){
        oishisa_base += q.top().first;
        ++exist_neta[q.top().second];
        ++num_neta;
        q.pop();
        ok = true;
        break;
      }else{
        q.pop();
      }
    }
    if(!ok){break;}
    // 最大値を残す
    oishisa_max = max(oishisa_max, oishisa_base + num_neta*num_neta );
  }
  cout << oishisa_max << "\n";
}