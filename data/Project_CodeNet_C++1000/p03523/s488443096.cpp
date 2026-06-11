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
  string S;
  cin >> S;
  vector<string> vec;
  vec.pb("AKIHABARA");
  vec.pb("AKIHABAR");
  vec.pb("AKIHABRA");
  vec.pb("AKIHABR");
  vec.pb("AKIHBARA");
  vec.pb("AKIHBAR");
  vec.pb("AKIHBRA");
  vec.pb("AKIHBR");
  vec.pb("KIHABARA");
  vec.pb("KIHABAR");
  vec.pb("KIHABRA");
  vec.pb("KIHABR");
  vec.pb("KIHBARA");
  vec.pb("KIHBAR");
  vec.pb("KIHBRA");
  vec.pb("KIHBR");
  rep(i,16)
  {
    if(S==vec[i]) 
    {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
