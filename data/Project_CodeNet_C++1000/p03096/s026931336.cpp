#include <iostream>

using namespace std;

int const nmax = 200000;
int const modulo = 1000000007;
int v[1 + nmax], freq[1 + nmax];
int dp[1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  dp[0] = 1;
  for(int i = 1;i <= n; i++){
    dp[i] = dp[i - 1];
    if(0 < freq[v[i]] && freq[v[i]] < i - 1)
      dp[i] += dp[freq[v[i]]];
    if(modulo <= dp[i])
      dp[i] -=  modulo;
    freq[v[i]] = i;
  }
  cout << dp[n];
  return 0;
}
