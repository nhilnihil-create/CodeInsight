/* When Talent doesn't work, Hard work beats Talent*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include"bits/stdc++.h"

using namespace std;

#define Fast_D cout<<fixed<<setprecision(13);
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl "\n"
#define int long long
#define double long double
#define all(v) v.begin(),v.end()
#define scanstr(s) cin>>ws; getline(cin,s);
//#define Local = 1;
#ifdef Local
#define debug(x) cout << __LINE__ << " " << #x <<"..." << x << endl
#define dev(x) cout << __LINE__ << " " << #x << "..." ; for(auto &it : x) cout<< it << " "; cout << endl;
#define des(x) cout << __LINE__ << " " << #x << "..." << x << endl;
#else
#define debug(x) ;
#define dev(x);
#define des(x)
#endif

const double PI = 3.141592653589793;

void solve()
{
	int n,x;
	cin >> n >> x;
	vector <int> a(n+1);
	a[0] = x;
	for(int i=1;i<n+1;i++) cin >> a[i];
	sort(all(a));
	int sz = a.size();
	vector <int> dif;
	for(int i=0;i<sz-1;i++)
	{
		dif.push_back(a[i+1]-a[i]);
	}
	int ans = dif[0];
	for(int i=0;i<dif.size();i++)
	{
		ans = __gcd(ans,dif[i]);
	}
	cout << ans ;
}

int32_t main()
{
	FastIO;
	Fast_D;
	int T;
	T = 1;
	while(T--) solve();
	return 0;
}

