#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i = 0;i <n;i++)
int main(){
	int n,M; cin >> n>>M; vector<long long> m(n);
	vector<vector<long long>> a(3, vector<long long>(n));
	rep(i, n) cin >> a[0][i] >> a[1][i] >> a[2][i];
	long long int ans = 0, sum = 0;
	rep(i, 1 << 3) {
		sum = 0;
		rep(k, n) {
			m[k] = 0;
			rep(j, 3) {
				if (i&(1 << j)) m[k] -= a[j][k];
				else m[k] += a[j][k];
			}
		}sort(m.rbegin(), m.rend());
		rep(k, M) sum += m[k];
		ans = max(ans, sum);
	}cout << ans << endl;
}