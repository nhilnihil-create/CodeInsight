#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
  string s;
  int cnt = 0;
  cin >> s;
  for (size_t i = 0; i < 3; i++)
  {
    if (s[i] == '1') cnt++;
  }
  cout << cnt << endl;  
  return 0;
}
