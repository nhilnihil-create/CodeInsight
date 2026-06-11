#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define sort(a) sort(a.begin(),a.end())
typedef long long ll;
const int MOD = (int)(1e9+7);
const int INF = (int)(1e9+1e7);
const ll INFL = (ll)(1e17);
const double EPS = 1e-8;
using namespace std;
int main()
{
  ll A,B,C;
  cin >> A >> B >> C;
  cout << B + min(C,B+A+1) << endl;
}