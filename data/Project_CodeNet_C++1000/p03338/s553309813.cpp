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
  int N;
  cin >> N;
  string a;
  cin >> a;

  int MAX = 0; 
  REP(i,N-1){
    int flag = 0;
    int cnt = 0;
    FOR(k,97,123){
      flag = 0;
      REP(j,i+1){
        if(a.at(j) == k){
          flag = 1;
          break;
        }
      }
      FOR(j,i+1,N){
        if(a.at(j) == k && flag == 1){
          cnt++;
          break;
        }
      }
    }
    MAX = max(MAX,cnt);
  }
  cout << MAX << endl;
}