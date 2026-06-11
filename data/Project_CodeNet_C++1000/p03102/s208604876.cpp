#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int N, M, C, sum = 0, ans = 0;
  cin >> N >> M >> C;
  
  vector<int> vecA(M), vecB(M);
  
  for(int i = 0; i < M; i++){
    cin >> vecB.at(i);
  }
  for(int j = 0; j < N; j++){
    for(int k = 0; k < M; k++){
      cin >> vecA.at(k);
      sum += vecB.at(k) * vecA.at(k);
    }
    if(sum + C > 0){
      ans += 1;
      sum = 0;
    }
    else{
      sum = 0;
    }
  }
  cout << ans << endl;
}
