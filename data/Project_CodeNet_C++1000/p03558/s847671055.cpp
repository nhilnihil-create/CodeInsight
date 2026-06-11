#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define DBG_N(hoge) cerr<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
ll dist[222222];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll k;cin>>k;
  for(int i=0;i<222222;i++)dist[i]=llINF;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>que;
  que.push({1,1});
  while(!que.empty()){
    ll now=que.top().F;
    ll cost=que.top().S;
    now%=k;
    que.pop();
    if(dist[now]<=cost)continue;
    dist[now]=cost;
    if(dist[(now+1)%k]>cost+1){que.push({(now+1)%k,cost+1});}
    if(dist[(now*10)%k] > cost){que.push({(now*10)%k,cost});}
  }
  cout<<dist[0]<<endl;
  return 0;
}
