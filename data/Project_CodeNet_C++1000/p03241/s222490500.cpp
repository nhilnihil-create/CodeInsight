#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

int main()
{
  int n, m;
  cin >> n >> m;
  
  vector<int> div(0);
  for(int i = 1; i*i <= m; i++)
    if(m%i == 0)
      div.emplace_back(i), div.emplace_back(m/i);
  sort(div.begin(), div.end());
  
  int res = 0;
  for(auto x : div)
    if(m/x >= n) res = x;
  cout << res << endl;
  
  return 0;
}