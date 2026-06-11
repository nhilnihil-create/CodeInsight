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
  int A,B,K;
  cin >> A >> B >> K;
  vector<int> vec(1,1);
  for(int i=2;i<=100;i++)
  {
    if(A%i==0&&B%i==0)
    {
      vec.push_back(i);
    }
  }
  sort(RALL(vec));
  cout << vec[K-1] << endl;
  return 0;
}
