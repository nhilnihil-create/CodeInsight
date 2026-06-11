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
  ll A,B;
  cin >> A >> B;
  int K;
  cin >> K;
  set<int> s;
  int C = A;
  if(A==B)
  {
    cout << A << endl;
    return 0;
  }
  rep(i,K)
  {
    s.insert(A);
    A ++;
    if(A==B)
    {
      break;
    }
  }
  rep(i,K)
  {
    s.insert(B);
    B --;
    if(C==B)
    {
      break;
    }
  }
  int N = s.size();
  rep(i,N)
  {
    int n = *begin(s);
    cout << n << endl;
    s.erase(n);
  }
  return 0;
}
