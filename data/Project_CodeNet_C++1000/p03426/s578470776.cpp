#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  ll H,W,D;
  cin >> H >> W >> D;
  vector<vector<ll>> A(H,vector<ll>(W));
  REP(i, H){
    REP(j, W){
      cin >> A.at(i).at(j);
      A.at(i).at(j)--;
    }
  }
  
  ll Q;
  cin >> Q;
  vector<P> B(Q);
  REP(i,Q){
    cin >> B[i].first >> B[i].second;
    B[i].first--;
    B[i].second--;
  }
  
  vector<P> number(H*W);
  REP(i,H){
    REP(j,W){
      number[A.at(i).at(j)]=make_pair(i,j);
    }
  }

  vector<ll> costlist(H*W);
  REP(i,D){
    ll cnt = 0;
    for(ll j=i;j+D<H*W;j+=D){
      ll y = number[j].first;
      ll x = number[j].second;
      ll ny = number[j+D].first;
      ll nx = number[j+D].second;
      cnt+=abs(x-nx)+abs(y-ny);
      costlist[j+D]=cnt;
    }
  }

  REP(i,Q){
    cout << costlist[B[i].second]-costlist[B[i].first] << endl;
  }
}