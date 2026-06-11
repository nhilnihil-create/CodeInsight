#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
using namespace std;
#define _GLIBCXX_DEBUG
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pii pair<long long,long long>
#define ppii pair<long long,pair<long long,long long>>
#define all(x) (x).begin(),(x).end()
#define rep(x) for(int i = 0;i < (x);i++)
#define repj(x) for(int j = 0;j < (x);j++)
#define REP(i,x) for(int (i) = 0;(i) < (x);(i)++)
#define rrep(x) for(int i = (x);i >= 0;i--)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define mod 1000000007
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define pyes cout << "Yes" << endl
#define pno cout << "No" << endl
typedef vector<vector<long long>> vii;
typedef unsigned long long lint;
typedef unsigned long long ll;
lint qp(int a, ll b) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
lint qp(int a, ll b, int mo) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
lint gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
long long INF = 1e14;
const int MAX_N = 1 << 17;
const int cf = 100010;
///////////////////////////////////////////////////////////////////////////////

int main(void) {
	lint n; cin >> n;
	vector<int> a(n);
	rep(n) cin >> a[i];
	if (n == 2) {
		sort(all(a));
		printf("%d %d", a[1], a[0]);
		return 0;
	}
	sort(all(a));
	//reverse(all(a));
	double k = (double)a[n-1] / 2;
	int j = n-2;
	for (int i = 0; i < n-1; i++)
	{
		if ((double)a[i] > k) {
			j = i;
			break;
		}
	}
	if ((double)a[j] - k < k - (double)a[j - 1]) {
		printf("%d %d", a[n - 1], a[j]);
	}
	else {
		printf("%d %d", a[n - 1], a[j-1]);
	}
	return 0;

}