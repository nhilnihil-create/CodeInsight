#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int a,b;
  cin >> a >> b;
  a--, b--;
  char grid[100][100];
  REP(i,100) REP(j,100){
	grid[i][j] = (i<50 ? '#' : '.');
  }
  int cnt = 0;
  for(int i = 0; i < 50; i+=2){
    if(cnt==a) break;
    for(int j = (i%2==0 ? 0 : 1); j < 100; j+=2){
      if(cnt==a) break;
      grid[i][j] = '.';
      cnt++;
    }
  }
  cnt = 0;
  for(int i = 99; i > 50; i-=2){
    if(cnt==b) break;
    for(int j = (i%2==0 ? 0 : 1); j < 100; j+=2){
      if(cnt==b) break;
      grid[i][j] = '#';
      cnt++;
    }
  }
  puts("100 100");
  REP(i,100){ 
    REP(j,100){
      cout << grid[i][j];
    }
    cout << '\n';
  }
  return 0;
}
