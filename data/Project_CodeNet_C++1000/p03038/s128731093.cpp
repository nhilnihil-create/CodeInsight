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
  ll N,M;
  cin >> N >> M;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  sort(ALL(A));
  vector<vector<ll>> B(M,vector<ll>(2));
  REP(i, M){
      cin >> B.at(i).at(1) >> B.at(i).at(0);
  }
  sort(ALL(B));
  ll j = M-1;
  REP(i,N){
    if(j>=0&&B.at(j).at(0)>A.at(i)&&B.at(j).at(1)>0){
      A.at(i)=B.at(j).at(0);
      B.at(j).at(1)--;
      if(B.at(j).at(1)==0){
        j--;
      }
    }else if(j<0||B.at(j).at(0)<=A.at(i)){
      break;
    }
  }

  ll sum = 0;
  REP(i,N){
    sum+=A[i];
  }

  cout << sum << endl;
}