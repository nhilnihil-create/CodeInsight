#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
  }*/

int mypow(int a, int b)
{
  if(b == 0) return 1; 
  return mypow(a*a%mod, b/2)*(b%2?a:1)%mod;
}

signed main()
{
  vi f(100010), s(100010);
  f[0] = 1;
  repi(i, 1, 100010) f[i] = f[i-1]*i%mod;
  repi(i, 1, 100010) s[i] = (s[i-1]+mypow(i, mod-2))%mod;

  int n;
  cin >> n;

  vi a(n);
  int res = 0;
  rep(i, n){
    cin >> a[i];
    res += (s[i+1]+s[n-i]-1)*a[i]%mod;
    res %= mod;
  }

  res *= f[n];
  res %= mod;

  cout << res << endl;

  return 0;
}
