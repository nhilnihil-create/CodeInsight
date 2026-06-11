#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,k;
  cin >> n >> k;
  vector<int>S(n+1);
  S[0] = 1;
  for(int i = 1; i <= n; i++)
  {
    S[i] = min(2*S[i-1], S[i-1] + k);
  }
  cout << S[n] << endl;
  return 0;
}
