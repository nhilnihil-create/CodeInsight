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

#define debug(x) cout << __LINE__ << " " << #x <<"..." << x << endl

const double PI = 3.141592653589793;

int pref[100001] ;

void solve()
{
	int n,q;
	string s;
	cin >> n >> q >> s;
	for(int i=0;i<n;i++)
	{
		if(s[i]== 'C' && s[i-1]=='A')
		{
			pref[i] = pref[i-1]+1;
		}
		else pref[i] = pref[i-1];
	}
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		cout << pref[r-1] - pref[l-1] << nl;
	}
}

int32_t main()
{
	FastIO;
	Fast_D;
	int T;
	T=1;
	while(T--) solve();
	return 0;
}

