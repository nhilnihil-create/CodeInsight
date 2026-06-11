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
//const ll MOD=998244353LL;
//const ll MAX_V=114514LL;
const ll MAX = 510000LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};

int main(){
  ll m,k;cin>>m>>k;
  if(m==0){
    if(k==0){
      cout<<0<<" "<<0<<endl;
    }
    else cout<<-1<<endl;
    return 0;
  }
  if(m==1){
    if(k==0){
      cout<<0<<" "<<0<<" "<<1<<" "<<1<<endl;
    }
    else cout<<-1<<endl;
    return 0;
  }
  ll MAX=1;
  rep(i,m)MAX*=2;
  if(k>=MAX)cout<<-1<<endl;
  else {
    deque<ll>q;
    q.push_back(k);
    rep(i,MAX){
      if(i==k)continue;
      q.push_front(i);
      q.push_back(i);
    }
    q.push_back(k);
    MAX*=2;
    rep(i,MAX-1)cout<<q[i]<<" ";
      cout<<q[MAX-1]<<endl;
    
  }
}
  
  
