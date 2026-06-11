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
  vector<int> A(N),B(N);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  int sum = 0;
  for(int i=1;i<N+1;i++)
  {
    int candy = 0;
    for(int j=0;j<i;j++)
    {
      candy += A[j];
    }
      for(int k=i-1;k<N;k++)
      {
        candy += B[k];
        sum = max(sum,candy);
      }
  }
  cout << sum << endl;
  return 0;
}
