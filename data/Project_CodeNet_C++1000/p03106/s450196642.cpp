#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  int cnt = 0;
  for (int i = min(A,B); i >= 1; i--)
  {
    if (A % i == 0 && B % i == 0)
    {
      cnt++;
    }
    if (cnt == K)
    {
      cout << i << endl;
      return 0;
    }
    
  }

  return 0;
}
