#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  string s,t;
  cin >> s >> t;
  int N,M;
  N = s.size();
  M = t.size();
  int m = min(N,M);
  int count = 0;
  bool ans = false;
  if(N<M)
  {
    rep(i,N)
    {
      if(s[i]==t[i])
      {
        count ++;
        if(count == N)
        {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  sort(ALL(s));
  sort(RALL(t));
  if(s[0]<t[0])
  {
    cout << "Yes" << endl;
    return 0;
  }
  else if(s[0]>t[0])
  {
    cout << "No" << endl;
  }
  rep(i,m)
  {
    if(s[i]==t[i])
    {
      continue;
    }
    else if(s[i]<t[i])
    {
      ans = true;
      break;
    }
    else
    {
      ans = false;
      break;
    }
    
  }
  if(ans == true)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  
  return 0;
}
