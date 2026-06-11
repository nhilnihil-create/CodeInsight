#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
int MAX = 100010;

void
dfs(long sum, long _max, int bit_flag, long& ans)
{
  if(sum > _max) return;
  if(bit_flag == 0b111) ans++;

  dfs(10 * sum + 7, _max, bit_flag | 0b001, ans);
  dfs(10 * sum + 5, _max, bit_flag | 0b010, ans);
  dfs(10 * sum + 3, _max, bit_flag | 0b100, ans);

}

int 
main() 
{
  long n; cin >> n;
  long ans = 0;
  dfs(0, n, 0, ans);

  cout << ans << endl;
  return 0;

}


