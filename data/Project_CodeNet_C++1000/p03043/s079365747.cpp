#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n,k;
  cin >> n >> k;
  
  ld p[n+1];
  rep1(i,n)
  {
    int score = i;
    if(score >= k)
    {
      while(i <= n)
      {
        p[i] = (long double)(1.0/(long double)n);
        i++;
      }
      break;
    }
    
    p[i] = (long double)(1.0/(long double)n); 
    while(score < k)
    {
      score *= 2;
      p[i] *= (long double)(1.0/2.0);
    }
  }
  
  ld ans = 0.0;
  rep1(i,n)
  {
    ans += (long double)p[i];
  }
  
  cout << fixed;
  cout << setprecision(20);
  cout << (long double)ans << endl;
  
}
