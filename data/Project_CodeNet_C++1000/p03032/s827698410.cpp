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
const int inf = 1 << 20;
ll n, m, x, y, q, d,z, w = 0, sum = 0, ans = 0;
const int MAX = 510000;
const int MOD = 1000000007;
int main(void) {
	cin >> n >> m; vector<int> a(n),c;
	rep(i, n) cin >> a[i];
	rep(i, m + 1) {
		for (int j = 0; i + j <= min(m, n); j++) {
			priority_queue<int>pq;
			rep(k, i) pq.push(a[k] * -1);
			for (int k = n - 1, c = 0; c < j; c++, k--)pq.push(a[k] * -1);
			for (int k = i + j; k < m; k++) {
				if (!pq.empty() && pq.top() > 0)pq.pop();
			}sum = 0;
			while (!pq.empty())sum -= pq.top(), pq.pop();
			ans = max(sum, ans);
		}
	}cout << ans << endl;
}