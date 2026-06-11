#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = " << x << endl;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define MSET(c, v) memset(c, v, sizeof(c))

const int INF = 0x3F3F3F3F; 
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const ll mod = 998244353;
const double EPS = 1e-10;

const int maxn = 1e6 + 100;

ll exp(ll a, ll b)
{
  ll ans = 1;
  while(b)
  {
    if(b & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}



int main()
{
  ios::sync_with_stdio(0);
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  int cnt = 0;
  if(s[0] == '0')
    cnt++;

  int ans = 0;
  int j = 0;
  for(int i = 0 ; i + 1 < n ; i++)
  {
    if(s[i] == '1' && s[i + 1] == '0')
      cnt++;
    while(j + 1 < n && cnt > k)
    {
      if(s[j] == '0' && s[j + 1] == '1')
        cnt--;
      j++;
    }
    ans = max(ans, i - j + 1);
  }

  cout << ans + 1 << endl;

  return 0;
}