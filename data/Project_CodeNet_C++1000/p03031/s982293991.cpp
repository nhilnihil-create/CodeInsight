#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <complex>
#include <ctime>
#include<bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef int itn;
const ll LINF = 1e18;
const int INF = 1e9;

//マクロ定義
#define vvint(vec,n,m,l) vector<vector<int>> vec(n, vector<int>(m,l));	// lで初期化
#define vvll(vec,n,m,l) vector<vector<ll>> vec(n,vector<ll>(m,l));
#define vint vector<int>
#define pint pair<int,int>
#define rep(i,a) for(ll i=0;i<(a);i++)
#define all(x) (x).begin(),(x).end()
#define debug system("pause")				//デバッグ用
#define ret return 0

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using Graph = vector<vector<ll>>;

#define ketasitei setprecision(15) //15桁表示

const ll MOD = 1000000007;
const double PI = 3.1415926535897932;


int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	//ll n, k;
	//cin >> n >> k;
	//vector<ll> a(n);
	//rep(i, n)
	//{
	//	cin >> a[i];
	//}
	//
	//ll ok = 1000000001;
	//ll ng = 0;

	//while (abs(ok - ng) > 1)
	//{
	//	ll mid = (ok + ng) / 2;
	//	if (isOK(mid,k,a))
	//	{
	//		ok = mid;
	//	}
	//	else
	//	{
	//		ng = mid;
	//	}
	//}

	//cout << ok << endl;
	
	ll n, m;
	cin >> n >> m;
	vector<ll> k(m);
	vector<vector<ll>> s(m, vector<ll>());
	vector<ll> p(m);

	rep(i, m)
	{
		cin >> k[i];
		rep(j, k[i])
		{
			ll tmp;
			cin >> tmp;
			s[i].push_back(tmp);
		}
	}
	rep(i, m)
		cin >> p[i];

	ll ans = 0;

	ll bits = (1 << n) - 1;
	//全部0の場合も調べたいのなら条件を変更するか、別途その分だけプログラムを書く
	while (bits + 1)
	{
		bool ok = true;
		ll tmp = bits;
		for (int i = 0; i < m; i++)
		{
			ll sum = 0;
			for (int j = 0; j < s[i].size(); j++)
			{
				if ((tmp >> (s[i][j] - 1)) & 1)
				{
					sum++;
				}
			}
			if (sum % 2 != p[i])
				ok = false;
		}

		if (ok)
			ans++;

		bits--;
	}

	cout << ans << endl;

	return 0;
}