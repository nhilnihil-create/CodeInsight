#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}



int main(void)
{
  string s;
  cin >> s;
  s += "ooooooooooooooo";
  int cnt = 0;
  REP(i, 15) {
    cnt += (s[i]=='o'?1:0);
  }
  cout << (cnt>=8?"YES":"NO") << endl;
}
