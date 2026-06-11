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
  char c1,c2,c3,c4,c5,c6,c7,c8,c9;
  cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6 >> c7 >> c8 >> c9;
  cout << c1 << c5 << c9 << endl;
  return 0;
}
