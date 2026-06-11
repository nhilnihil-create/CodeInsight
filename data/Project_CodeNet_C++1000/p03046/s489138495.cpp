#include<bits/stdc++.h>

using namespace std;

using   ll=long long;
using   ld=long double;

#define fast        	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define endl        	"\n"
#define pb          	push_back
#define mp          	make_pair
#define F           	first
#define S           	second
#define int          long long int
#define pll				   pair<int , int>

#define ALL(v)       v.begin(),v.end()
#define ALLR(v)      v.rbegin(),v.rend()
#define pii          3.14159265358979323
#define inf     		 LLONG_MAX
#define ones(x)      __builtin_popcount(x)
#define fill(a,b)    memset(a,b,sizeof(a))
#define mod 			   1000000007
#define hell         998244353

ll mod_pow(ll a,ll b,ll m)
{
    ll res = 1;
    while(b)
    {
        if(b&1)
        {
        	res=(res*a) % m;
        }
        a=(a*a) % m;
        b>>=1;
    }
    return res;
}

ll mod_inverse(ll a)
{
	return mod_pow(a , mod-2 , mod);
}

void solve()
{
  int n , k;

  cin >> n >> k;

  if(k >= (1LL<<n)) {
    cout << -1 << endl;
    return;
  }

  if(n == 0) {
    if(k == 0) {
      cout << 0 << " " << 0;
      return;
    }
    else {
      cout << -1;
      return;
    }
  }
  else if(n == 1) {
    if(k == 0) {
      cout << 0 << " " << 0 << " " << 1 << " " << 1;
      return;
    }
    else {
      cout << -1;
      return;
    }
  }
  else {
    vector< int > v;

    for(int i = 0; i < (1<<n); ++i) {
      if(i != k) {
        v.push_back(i);

        cout << i << " " ;
      }
    }

    cout << k << " ";

    reverse(ALL(v));

    for(auto u : v) {
      cout << u << " ";
    }

    cout << k;
  }
}


signed main() {
    fast;

    int t = 1;

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

	  //cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
