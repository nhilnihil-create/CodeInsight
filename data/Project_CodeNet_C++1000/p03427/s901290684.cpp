#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
const long long INF = 1LL << 60;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
vector<char> Alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int main()
{
  cout << fixed << setprecision(10);
  string N;
  cin >> N;
  int n = N.size();
  bool ok = true;
  bool ifok = false;
  if(n==1)
  {
    cout << N << endl;
    return 0;
  }
  rep(i,n)
  {
    if(N[i]!='9'&&i==0)
    {
      ifok = true;
      continue;
    }
    if(N[i]!='9')
    {
      ok = false;
      break;
    }
  }
  if(ifok&&ok)
  {
    int num = N[0] - '0';
    cout << num + 9 * (n-1) << endl;
    return 0;
  }
  if(ok)
  {
    cout << 9 * n << endl;
  }
  else
  {
    int num = N[0] - '1';
    cout << num + 9 * (n-1) << endl;
  }
  return 0;
}
