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
  string S;
  cin >> S;
  vector<int> counte(N);
  vector<int> countw(N);
  int e=0,w=0;
  rep(i,N)
  {
    if(S[i]=='E') e ++;
    else w ++;
    counte[i] = e;
    countw[i] = w;
  }
  int x = counte[N-1];
  int m = P;
  rep(i,N)
  {
    int z = 0;
    if(i!=0)
    {
      z += countw[i-1];
    }
    z += x - counte[i];
    m = min(m,z);
  }
  cout << m << endl;
  return 0;
}
