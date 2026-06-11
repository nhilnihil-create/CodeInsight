//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef long long ijt;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;

const long long INF = 1LL << 55;

#define itn int
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
#define rrep(i,n) for(int i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }

#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main(void) {
	int n;cin >> n;
	vector<ijt> a(n),c(n+1,0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		c[i+1] = c[i] + a[i];
	}

	//真ん中の位置iにたいして切るべき適切な左と右の個所を決定する
	//まずは左。
	vector<int> left(n,0),right(n,0);
	//2番目からn-2番目まで
	int j = 1;
	int t = 3;
	for (int i = 2; i <= n - 2; i++) {
		//今j番目で区切っているとする
		//c[j]とc[i]-c[j]の差の絶対値はどこかで最小になる、それを見つける
		//ただし1 <= j <= i-1に注意
		//j = 1;
		while (j < i - 1) {
			if (abs(2 * c[j] - c[i]) > abs(2 * c[j + 1] - c[i])) {
				j++;
			}else break;
		}
		left[i] = j;

		//右側、今度はi+1 <= j <= n-1に注意する
		//t = i+1;
		while (t < n - 1) {
			if (abs((c[t] - c[i]) - (c[n] - c[t])) > abs((c[t + 1] - c[i]) - (c[n] - c[t + 1]))) {
				t++;
			}else break;
		}
		right[i] = t;
	}

	//2 <= i <= n-2で全探索
	ijt ans = INF;
	for (int i = 2; i <= n - 2; i++) {
		ijt p,q,r,s;
		p = c[left[i]];
		q = c[i] - c[left[i]];
		r = c[right[i]] - c[i];
		s = c[n] - c[right[i]];
		ijt d = max({p,q,r,s}) - min({p,q,r,s});
		mins(ans,d);
	}
	cout << ans << endl;

}