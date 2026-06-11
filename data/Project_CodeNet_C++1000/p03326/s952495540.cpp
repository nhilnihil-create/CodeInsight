#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e12
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
  
int main()
{
  ll N,M;
  cin >> N >> M;
  vector<vector<ll>> A(N,vector<ll>(3));
  REP(i, N){
    REP(j, 3){
      cin >> A.at(i).at(j);
    }
  }

  ll MAX = 0;
  REP(i,1<<3){
    bitset<3> bs(i);
    vector<P> vec(N);
    REP(j,N){
      ll cnt = 0;
      REP(k,3){
        if(bs[k]==0){
          cnt+=A.at(j).at(k);
        }else{
          cnt+=-A.at(j).at(k);
        }
      }
      vec[j].first=cnt;
      vec[j].second=j;
    }
    sort(ALL(vec));
    reverse(ALL(vec));
    ll ans=0;
    ll x=0,y=0,z=0;
    REP(j,M){
      ans+=vec[j].first;
      x+=A[vec[j].second][0];
      y+=A[vec[j].second][1];
      z+=A[vec[j].second][2];
    }
    if(((x>=0&&bs[0]==0)||(x<0&&bs[0]==1))&&((y>=0&&bs[1]==0)||(y<0&&bs[1]==1))&&((z>=0&&bs[2]==0)||(z<0&&bs[2]==1))){
      MAX=max(MAX,ans);
    }
  }

  cout << MAX << endl;
}