#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;

  string A = S.substr(0,N);
  string B = S.substr(N);
  reverse(ALLOF(B));
  
  map<string,ll> memo;
  for(int i=0; i<(1<<N); i++){
    string x, y;
    rep(j,B.size()){
      if((i>>j)&1) x += B[j];
      else y += B[j];
    }

    memo[x + "_" + y]++;
  }

  ll ret = 0;
  for(int i=0; i<(1<<N); i++){
    string x, y;
    rep(j,A.size()){
      if((i>>j)&1) x += A[j];
      else y += A[j];
    }

    //cout << x + "_" + y << "\t" << memo[x + "_" + y] << endl;
    
    ret += memo[x + "_" + y];
  }

  cout << ret << endl;
  
  return 0;
}
