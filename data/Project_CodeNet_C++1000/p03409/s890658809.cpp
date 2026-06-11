#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
typedef long long int ll;
typedef long double ld;
const ll INF = (1 << 31) - 1;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MAX = 510000;
const ll MOD = 1000000007;
int ans = 0, n,k;
int main() {
	cin >> n;
	vector<pair<int, int>> a(n), c(n);
	int p, q; vector<bool> b(100, true);
	rep(i, n) {
		cin >> p >> q;
		a[i] = make_pair(q, p);
	}
	rep(i, n) {
		cin >> p >> q;
		c[i] = make_pair(p, q);
	}
	sort(a.begin(), a.end());
	sort(c.begin(), c.end());
	rep(i, n) {
		k = -1;
		rep(j, n) {
			if (c[i].first > a[j].second &&c[i].second >a[j].first &&b[j])
				k = j;
		}
		if (k != -1) {
			ans++; b[k] = false;
		}
	}cout << ans << endl;
}