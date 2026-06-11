#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
	std::fill((T*)array, (T*)(array + N), val);
}
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll INF =  1LL << 60;
const int inf = 1 << 30;
int n, m, x, y,q;ll z, w=0, sum = 0, ans = 0;
const int MAX = 510000;
const int MOD = 1000000007;
int main(void) {
	int n, m, k; cin >> n; vector<int> a(n), b(n), c(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n) cin >> c[i];
	sort(ALL(a)); sort(ALL(b)); sort(ALL(c));
	rep(i, n) {
		sum += 1LL * (lower_bound(ALL(a), b[i]) - a.begin()) *( n - (lower_bound(ALL(c), b[i] + 1) - c.begin()));
	}cout << sum << endl;
}