// AtCoder.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// AtCoder.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//


#define _USE_MATH_DEFINES
#include<math.h>

//#include<cmath>

#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>



//#include "Ants.h"
using namespace std;
typedef long long ll;
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i,n) for(int i=0;i<n;i++)
#define show(s) cout<<s<<endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define LINF (1000000000000000000ll)
#define MOD (1e9+7)
typedef pair < ll, ll> P;
ll gcd(ll a, ll b) {//最大公約数を求める///最大公倍数a*b/gcd(a,b)
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcd(ll a, ll b) {//最小公倍数を求める　b=0のときaを返す
	if (b == 0) return a;
	return (a / gcd(a, b)) * b;
}
vector<int> divnum(ll num) {
	int dig;
	vector<int>p;
	while (num) {
		dig = num % 10;
		p.push_back(dig);
		num /= 10;
	}
	return p;
}
int digiter(ll num) {
	int dig;
	vector<int>p;
	while (num) {
		dig = num % 10;
		p.push_back(dig);
		num /= 10;
	}
	return p.size();
}
vector<int> convertstring(string s) {
	vector<int> d;
	ll n = s.size();
	rep(i, n) {
		d.push_back(s[i] - '0');
	}
	return d;
}
map< int64_t, int > prime_factor(int64_t n) {
	map< int64_t, int > ret;
	for (int64_t i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
}
vector<ll> divisor(ll n) {
	vector<ll>res;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i != 0)continue;
		res.push_back(i);
		if (i * i != n)res.push_back(n / i);
	}
	return res;
}


ll myPow(ll x, ll n, ll m) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return myPow(x * x % m, n / 2, m);
	else
		return x * myPow(x, n - 1, m) % m;
}
std::vector<int> Eratosthenes(const int N)
{
	std::vector<bool> is_prime(N + 1);
	for (int i = 0; i <= N; i++)
	{
		is_prime[i] = true;
	}
	std::vector<int> P;
	for (int i = 2; i <= N; i++)
	{
		if (is_prime[i])
		{
			for (int j = 2 * i; j <= N; j += i)
			{
				is_prime[j] = false;
			}
			P.emplace_back(i);
		}
	}
	return P;
}

int N, C, D[35][35], c[505][505]; int sz[3][35];
int coster(int mpos, int y) {
	int res = 0;
	rep(x, C) {
		res+=D[x][y] * sz[mpos][x];
	}
	return res;
}
int main()
{
	cin >> N >> C;
	rep(x, C)rep(y, C)cin >> D[x][y];
	rep(i, N)rep(j, N)cin >> c[i][j];
	rep(i, N)rep(j, N) {
		sz[(i + j) % 3][--c[i][j]]++;
	}
	
	vector<int>d[3];
	rep(i, 3) {
		rep(j, C) {
			d[i].push_back(coster(i, j));
		}
		
	}
	int ans = INF;
	rep(i, C) {
		rep(j, C) {
			if (i == j)continue;
			rep(k, C) {
				if (i == k || j == k)continue;
				chmin(ans, d[0][i] + d[1][j] + d[2][k]);
			}
		}
	}
	cout << ans << endl;
}