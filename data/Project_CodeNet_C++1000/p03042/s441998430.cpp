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
  int N2 = N%100;
  N /= 100;
  bool ans1 = true;
  bool ans2 = true;
  if(N2==0)
  {
    ans2 = false;
  }
  if(N==0)
  {
    ans1 = false;
  }
  if(N2>12)
  {
    ans2 = false;
  }
  if(N>12)
  {
    ans1 = false;
  }

  if(ans1==true&&ans2==true)
  {
    cout << "AMBIGUOUS" << endl;
  }
  else if(ans1==true&&ans2==false)
  {
    cout << "MMYY" << endl;
  }
  else if(ans1==false&&ans2==true)
  {
    cout << "YYMM" << endl;
  }
  else
  {
    cout << "NA" << endl;
  }
  return 0;
}
