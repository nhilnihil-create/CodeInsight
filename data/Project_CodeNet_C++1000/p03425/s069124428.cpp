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
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i,N)
  {
    cin >> S[i];
  }
  vector<ll> vec(5);
  rep(i,N)
  {
    if(S[i][0]=='M')
    {
      vec[0] ++;
    }
    if(S[i][0]=='A')
    {
      vec[1] ++;
    }
    if(S[i][0]=='R')
    {
      vec[2] ++;
    }
    if(S[i][0]=='C')
    {
      vec[3] ++;
    }
    if(S[i][0]=='H')
    {
      vec[4] ++;
    }
  }
  ll product = 0;
  rep(i,5)
  {
    for(int j=i+1;j<5;j++)
    {
      for(int k=j+1;k<5;k++)
      {
        product += vec[i]*vec[j]*vec[k];
      }
    }
  }
  cout << product << endl;
  return 0;
}
