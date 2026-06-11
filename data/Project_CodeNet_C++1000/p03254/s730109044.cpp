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
  int N, x;
  cin >> N >> x;

  vector<int> a(N);
  REP(i, N) cin >> a[i];
  
  sort(ALL(a));
  int cnt = 0;
  int flag = 0;
  REP(i,N){
    x -= a.at(i);
    cnt++;
    if(x<0){
      cout << cnt - 1 << endl;
      flag = 1;
      break;
    }
  }
  if(flag == 0 && x != 0){
    cout << cnt - 1 << endl;
  }else if(flag == 0 && x == 0){
    cout << cnt << endl;
  }
}