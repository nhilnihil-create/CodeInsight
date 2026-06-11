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
  vector<bool> visited(k,false);
  auto c = [](pll a,pll b){return a.first>b.first;};
  priority_queue<pll,vector<pll>,decltype(c)> cost(c);
  // cost,node
  cost.push(make_pair(1ll,1ll));
  ll ans;
  while(!cost.empty()){
    pll nx = cost.top();
    cost.pop();
    //cout << nx.first << "," << nx.second << endl;
    if(nx.second==0){
      ans = nx.first;
      break;
    }
    if(visited[nx.second]) continue;
    else visited[nx.second] = true;
    if(!visited[(nx.second * 10ll)%k]) cost.push(make_pair(nx.first, (nx.second * 10ll)%k));
    if(!visited[(nx.second + 1ll)%k]) cost.push(make_pair(nx.first+1, (nx.second + 1ll)%k));
  }
  cout << ans << endl;
  return 0;
}
