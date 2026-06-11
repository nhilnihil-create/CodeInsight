#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif 

using namespace std;

#define TRACE(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << endl;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]";
	err(++it, args...);
}

#define MAXN ((ll)2e5+5)
#define MOD ((ll)1e9 + 7)
#define INF ((ll)1e9 + 9)
#define ll long long
#define _ << " " <<
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define LOG(x) if(DEBUG) cerr << x << endl;
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
#define pii pair<ll,ll>
#define mid ((l+r)/2)

ll n;
ll ct[105];
vector <ll> v;

bool prime(ll x)
{
	for (ll i = 2; i*i <= x; ++i)
		if(x%i==0)
			return false;
	return true;
}

ll rec(ll idx, ll cur)
{
	if(idx<0)
		return 0LL;

	ll ret = 0;
	for (ll i = 1; i <= min(cur, v[idx]); ++i)
	{
		if(cur == i)
			ret += 1;
		else if(cur % i == 0)
		{
			ll t = rec(idx-1, cur / i);
			ret += t;
		}
	}

	return ret;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;

	for (ll i = 2; i < 100; ++i)
		if(prime(i))
		{
			ll t = n;
			ll c = 0;
			while(t)
			{
				t = t / i;
				c += t;
			}

			ct[i] = c;
		}

	for (ll i = 0; i < 100; ++i)
		if(ct[i])
			v.pb(ct[i]+1);

	cout << rec(v.size()-1, 75) << endl;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/