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
  int N, M;
  cin >> N >> M;

  vector<vector<int>> A(N,vector<int>(M,0));
  REP(i, N){
    int K;
    cin >> K;
    REP(j, K){
      cin >> A.at(i).at(j);
    }
  }
  int flag = 0;
  int flag2 = 0;
  int cnt = 0;
  FOR(i,1,M+1){
    flag2 = 0;
    REP(j,N){
      flag = 0;
      REP(k,M){
        if(A.at(j).at(k)==i){
          flag = 1;
        }
      }
      if(flag == 0){
        flag2 = 1;
      }
    }
    if(flag2 == 0){
      cnt++;
    }
  }
  cout << cnt << endl;
}