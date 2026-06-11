/*{{{*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
// pll pp; -> (pp.first,pp.second)
// vector<vl> pp(n,vl(2)); sort(pp.begin(),pp.end(),[](vl a,vl b){return a[0]<b[0];});

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define RREP(i,n) for(ll (i)=(n)-1;(i)>=0;(i)--)
#define FOR(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
#define FORR(i,a,b) for(ll (i)=(b)-1;(i)>=(a);(i)--)
#define DEBUG(x) cout << #x << ": " << x << endl
#define CHMAX(a,b) a=max((a),(b))
#define CHMIN(a,b) a=min((a),(b))
/*}}}*/
int main() {
  ll k;
  cin >> k;
  deque<ll> deq;
  vl cost(k,-1);
  cost[1] = 1;
  deq.push_front(1ll);
  while(!deq.empty()){
    ll nx = deq[0];
    if(nx==0){
      break;
    }
    deq.pop_front();
    ll nf;
    nf = (nx* 10ll)%k;
    if(cost[nf]<0){
      deq.push_front(nf);
      cost[nf]=cost[nx];
    }else{
      if(cost[nf]>cost[nx]){
        cost[nf] = cost[nx];
        deq.push_front(nf);
      }
    }
    nf = (nx+ 1ll)%k;
    if(cost[nf]<0){
      deq.push_back(nf);
      cost[nf]=cost[nx]+1;
    }else{
      CHMIN(cost[nf],cost[nx]+1);
    }
  }
  cout << cost[0]<< endl;
  return 0;
}
