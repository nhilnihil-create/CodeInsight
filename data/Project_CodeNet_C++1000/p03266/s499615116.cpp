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
  ll N,K;
  cin >> N >> K;
  ll ans = 1;
  if(K==1)
  {
    cout << N*N*N << endl;
  }
  else if(K==2)
  {
    if(N%2==0)
    {
      cout << ((N/2)*(N/2)*(N/2)) * 2 << endl;
    }
    else
    {
      cout << ((N/2)*(N/2)*(N/2)) + (((N+1)/2)*((N+1)/2)*((N+1)/2)) << endl;
    }
  }
  else if(K%2!=0)
  {
    cout << (N/K) * (N/K) * (N/K) << endl;
  }
  else
  {
    if(N/(K/2)%2==0)
    {
      cout << (N/K) * (N/K) * (N/K) * 2 << endl;
    }
    else
    {
      cout << (N/K) * (N/K) * (N/K) + ((N/K)+1) * ((N/K)+1) * ((N/K)+1) << endl;
    }
  }
  
  return 0;
}
