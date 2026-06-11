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
  ll N;
  cin >> N;
  vector<vector<ll>> A(N-1,vector<ll>(3));
  REP(i, N-1){
    REP(j, 3){
      cin >> A.at(i).at(j);
    }
  }
  
  REP(i,N){
    ll now=0;
    FOR(j,i,N-1){
      //now以上のA.at(j).at(2)の倍数とA.at(j).at(1)のmax
      ll x;
      if(now%A.at(j).at(2)==0){
        x=now;
      }else{
        x=(now/A.at(j).at(2)+1)*A.at(j).at(2);
      }
      now=A.at(j).at(0)+max(A.at(j).at(1),x);
    }

    cout << now << endl;
  }
}