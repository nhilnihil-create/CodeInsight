///FUCKOUT
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
#include <ext/rope> //header with rope
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
//#define endl '\n'

using namespace __gnu_cxx; //namespace with rope and some additional stuff

using ll = long long;
using db = long double;
using row = vector<int>;
using ii = pair<ll, ll>;

const int N = 3e5+5, M = 1e6 + 5, LG = 17, MOD = 1e9 + 7;
const int BLOCK = 55;
const int BLOCKN = N / BLOCK + 1;
const long double EPS = 1e-7;
using ull = unsigned long long;

int32_t main(){
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  string s;
  char c;
  cin >> c; s.pb(c);
  cin >> c; s.pb(c);
  cin >> c; s.pb(c);
  cin >> c; s.pb(c);
  sort(s.begin(),s.end());
  if(s == "1479")
    cout << "YES\n";
  else
    cout << "NO\n";


  return 0;
}
