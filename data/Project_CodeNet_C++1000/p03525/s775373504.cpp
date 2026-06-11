#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int main(){
  int N;
  cin >> N;
  vector<int> D(N+1);
  vector<int> cntTime(13, 0);
  REP(i, N){
    cin >> D[i];
    cntTime[D[i]]++;
  }
  D[N] = 0;
  if(N >= 24){
    cout << 0 << endl;
    return 0;
  }
  // if(cntTime[12] >= 2 || cntTime[0] >= 2){
  //   cout << 0 << endl;
  //   return 0;
  // }
  REP(i, 12){
    if(cntTime[i] >= 3){
      cout << 0 << endl;
      return 0;
    }
  }
  if(N >= 23){
    cout << 1 << endl;
    return 0;
  }
  vector<int> a(N+1);
  int ans = 0;
  for(int bit = 0; bit < (1<<(N+1)); bit++){
    REP(i, N+1){
      if((bit>>i) & 1){
        a[i] = D[i];
      }
      else{
        a[i] = 24-D[i];
      }
    }
    int mind = INF;
    REP(i, N+1){
      FOR(j, i+1, N+1){
        int d = min(abs(a[i]-a[j]), 24-(abs(a[i]-a[j])));
        mind = min(d, mind);
      }
    }
    ans = max(mind, ans);
  }
  cout << ans << endl;
  return 0;
}
