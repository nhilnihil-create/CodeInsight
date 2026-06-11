#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  int m = prime.size();
  vector<int> p(m);
  for(int i = 0; i < m; i++)
  {
    int x = prime[i];
    for(int j = x; j <= n; j *= x)
    {
      p[i] += n / j;
    }
  }
  
  //rep(i, m) cout << p[i] << " "; cout << endl;
  
  int res = 0;
  for(int x : p) if(x >= 74) res++;
  //cout << res << endl;
  
  
  for(int i = 0; i < m; i++)
  {
    for(int j = i + 1; j < m; j++)
    {
      if(p[i] >= 24 && p[j] >= 2) res++;
      if(p[i] >= 2 && p[j] >= 24) res++;
      if(p[i] >= 14 && p[j] >= 4) res++;
      if(p[i] >= 4 && p[j] >= 14) res++;
    }
  }
  //cout << res << endl;
  
  for(int i = 0; i < m; i++)
  {
    for(int j = i + 1; j < m; j++)
    {
      for(int k = j + 1; k < m; k++)
      {
        if(p[i] >= 2 && p[j] >= 4 && p[k] >= 4) res++;
        if(p[i] >= 4 && p[j] >= 2 && p[k] >= 4) res++;
        if(p[i] >= 4 && p[j] >= 4 && p[k] >= 2) res++;
      }
    }
  }
  cout << res << endl;
  
  
  return 0;
}