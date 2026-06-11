// comb(n,r)でrを固定すればnが大きいほど大きい（分母が同じなので明らか）、同じ数列からa(i)>a(j)でcomb(a(i),a(j))を選ぶので、
// あるnを選んだときのrの候補は、このnよりも大きい数を選んだときの候補にすべて含まれる。
// 以上よりnについては与えられた数列より最大のものを選んでよい。
// また、nを固定したときcomb(n,r)を最大化するにはn/2に最も近いものを選べばよい（これはパスカルの三角形を考えれば明らか）。
// これは二分探索でlog(N)で求まる。C++ではlower_boundで簡単に実装できる。
// メモ→rは0~nをとりうる、n=2: 1 2 1 , n=3: 1 3 3 1 , n=4: 1 4 6 4 1, .. ← nが偶数ならn/2, nが奇数ならceil(n/2)=floor(n/2)←これに一番近い数

#define _USE_MATH_DEFINES 
#include<iomanip> 
#include<cmath>  
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<bitset>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
typedef long long ll;
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl
#define wl() cout << endl
const ll MAX_10p5 = 100010;
const ll MAX_10p9 = 1000000010;
const ll MAX_10p18 = 1000000000000000010;
const ll MOD = 1000000007;
const ll m4x[4] = { 1,0,-1,0 };
const ll m4y[4] = { 0,1,0,-1 };
const ll m8x[8] = { 1,1,0,-1,-1,-1,0,1 };
const ll m8y[8] = { 0,1,1,1,0,-1,-1,-1 };
const ll m9x[9] = { 1,1,0,-1,-1,-1,0,1,0 };
const ll m9y[9] = { 0,1,1,1,0,-1,-1,-1,0 };

struct edge {
	ll from, to, cost;
	bool operator<(const edge& right) const {
		return cost < right.cost;
	}
};
struct point {
	ll x, y;
	bool operator<(const point& right) const {
		return x == right.x ? y < right.y : x < right.x;
	}
};

///////////////////////////////////////////////////////////////////////////////////////

ll n, a[MAX_10p5], maxa, ansr;
ll *pos, idx;

int main() {
	cin >> n;
	repi(i, 0, n) rd(a[i]);

	sort(a, a + n);
	maxa = a[n - 1];

	if (maxa % 2 == 0) {
		ll key = maxa / 2;
		pos = lower_bound(a, a + n, key);
		idx = distance(a, pos);
		if (idx == 0) {
			ansr = a[idx];
		}
		else if (idx == n - 1) {
			ansr = a[idx - 1];
		}
		else {
			if (abs(key - a[idx]) < abs(key - a[idx - 1])) ansr = a[idx];
			else ansr = a[idx - 1];
		}
	}
	else {
		ll keys[2] = {};
		keys[0] = maxa / 2;
		keys[1] = (maxa + 1) / 2;
		ll mindiff = MAX_10p18;
		repi(i, 0, 2) {
			pos = lower_bound(a, a + n, keys[i]);
			idx = distance(a, pos);
			if (idx == 0) {
				if (mindiff > abs(a[idx] - keys[i])) {
					mindiff = abs(a[idx] - keys[i]);
					ansr = a[idx];
				}
			}
			else if (idx == n - 1)  {
				if (mindiff > abs(a[idx - 1] - keys[i])) {
					mindiff = abs(a[idx - 1] - keys[i]);
					ansr = a[idx - 1];
				}
			}
			else {
				if (abs(keys[i] - a[idx]) < abs(keys[i] - a[idx - 1])) {
					if (mindiff > abs(a[idx] - keys[i])) {
						mindiff = abs(a[idx] - keys[i]);
						ansr = a[idx];
					}
				}
				else
					if (mindiff > abs(a[idx - 1] - keys[i])) {
						mindiff = abs(a[idx - 1] - keys[i]);
						ansr = a[idx - 1];
					}
			}
		}
	}
	
	cout << maxa << " " << ansr << endl;

	return 0;
}
