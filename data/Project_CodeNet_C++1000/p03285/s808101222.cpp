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
  for(int i=0;i<100;i++)
  {
    for(int j=0;j<100;j++)
    {
      if(4*i+7*j==N) 
      {
        cout << "Yes" << endl; 
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
