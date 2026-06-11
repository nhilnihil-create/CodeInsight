#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;

int main()
{
  ll N;
  cin >> N;
  vector<vector<ll>> vec(N,vector<ll> (3));
  REP(i,N){
    cin >> vec.at(i).at(1) >> vec.at(i).at(2);
    vec.at(i).at(0)=vec.at(i).at(1)+vec.at(i).at(2);
  }

  sort(ALL(vec));
  reverse(ALL(vec));
  ll tk = 0;
  ll ao = 0;
  REP(i,N){
    if(i%2==0){
      tk+=vec.at(i).at(1);
    }else{
      ao+=vec.at(i).at(2);
    }
  }

  cout << tk-ao << endl;
}