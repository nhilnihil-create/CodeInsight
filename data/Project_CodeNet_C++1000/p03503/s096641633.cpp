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
  int N;
  cin >> N;
  vector<vector<int>> F(N,vector<int>(10));
  REP(i, N){
    REP(j, 10){
      cin >> F.at(i).at(j);
    }
  }
  vector<vector<int>> P(N,vector<int>(11));
  REP(i, N){
    REP(j, 11){
      cin >> P.at(i).at(j);
    }
  }
  
  int MAX = -INF;
  FOR(i,1,1024){
    int sum = 0;
    int z = i;
    REP(j,N){
      int x = z;
      int cnt = 0;
      REP(k,10){
        int y = x%2;
        x/=2;
        if(F.at(j).at(k)==1&&y==1){
          cnt++;
        }
      }
      sum+=P.at(j).at(cnt);
    }
    MAX=max(MAX,sum);
  }

  cout << MAX << endl;
}