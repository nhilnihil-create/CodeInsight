#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <complex>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>
#include <iomanip>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define Repr(e, b, i) for(int i = e; i >= b; i--)
#define rep(n, i) Rep(0, n-1, i)
#define repr(n, i) Repr(n-1, 0, i)
#define all(v) (v).begin(), (v).end()
#define pb(v) push_back(v)
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define bitcnt(x) __builtin_popcount(x)
#define fst first
#define snd second
#define Pqaz(T) priority_queue<T,vector<T>,greater<T>>
#define Pqza(T) priority_queue<T>
#define put(x) cout << x;
#define putsp(x) cout << x << ' ';
#define putbd cout << "---------------------------------------------" << endl;
#define putln(x) cout << x << endl;
#define debug(x) cerr << #x << "=" << x << endl;
#define ENJYU std::ios::sync_with_stdio(false);std::cin.tie(0);

typedef long long ll;
typedef pair<ll, ll> llP;
typedef pair<int, int> intP;
typedef complex<double> comp;
typedef vector <int> vec;
typedef vector <ll> vecll;
typedef vector <double> vecd;
typedef vector <vec> mat;
typedef vector <vecll> matll;
typedef vector <vecd> matd;

//vector の中身を出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

const int MAX = 200020;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const ll INFL = 1e18;
const ll MOD = 1e9+7;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
//const int dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1};

//********************************template END****************************************//

void solve(void){

	ll N;
	cin >> N;

	if (N <= 5)
	{
		if (N == 2 || N == 4 || N == 5)
		{
			cout << "No" << endl;
			return;
		}

		cout << "Yes" << endl;

		if (N == 1)
		{
			cout << 2 << endl;
			cout << 1 << ' ' << 1 << endl;
			cout << 1 << ' ' << 1 << endl;
		}

		if (N == 3)
		{
			cout << "3\n2 1 2\n2 3 1\n2 2 3" << endl;
		}

		return;
	}

	vecll cands;

	ll tmp = 1, x = 2;

	while(tmp <= 1e5)
	{
		cands.pb(tmp);
		tmp += x++;
	}

	//cout << cands << endl;

	auto p = lower_bound(all(cands), N);

	if (*p != N)
	{
		cout << "No" << endl;
		return;
	}

	cout << "Yes" << endl;

	ll idx = p - cands.begin() + 1;

	cout << idx+1 << endl;

	mat ans(idx+1, vec(idx, 0));

	ans[0][0] = 1;
	ans[1][0] = 1;

	int d = 2, u = 1, r = 0, l = 0;

	Rep(2, N, n)
	{
		ans[d][r] = n;
		ans[l][u] = n;
		r++;
		l++;
		if (*lower_bound(all(cands), n) == n)
		{
			u++, d++;
			l = r = 0;
		}
	}

	for (auto v : ans)
	{
		cout << idx << ' ';
		rep(idx, j)
		{
			cout << v[j] << (j == idx-1 ? '\n' : ' ');
		}
	}



}

int main(void){
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
