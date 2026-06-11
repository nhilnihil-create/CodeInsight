#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  vector<string> s(N);
  rep (i, N)
  {
    cin >> s[i];
  }
  
  int M;
  cin >> M;
  vector<string> t(M);
  rep (i, M)
  {
    cin >> t[i];
  }
  
  int max_money = 0;
  rep (i, N)
  {
    int money = 0;
    
    rep (j, N)
    {
      if (s[i] == s[j])
      {
        money++;
      }
    }
    
    rep (k, M)
    {
      if (s[i] == t[k])
      {
        money--;
      }
    }
    
    if (money > max_money)
    {
      max_money = money;
    }
  }
  
  cout << max_money << endl;
}
