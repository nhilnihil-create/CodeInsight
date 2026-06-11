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
	int n,m;
	cin >> n >> m;
	vector <int> x(m);
	for(int &it : x) cin >> it;
	sort(all(x));
	if(n>=m)
	{
		cout << "0\n";
		return ;
	}
	vector<int>dis;
	for(int i=0;i<m-1;i++)
	{
		dis.push_back(abs(x[i+1]-x[i]));
	}
	int ans = 0;
	sort(all(dis));
	for(int i=0;i<m-n;i++)
	{
		ans += dis[i];
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

