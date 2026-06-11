#include <bits/stdc++.h>
using namespace std;
const int maxn = 111;
int t[maxn], v[maxn];
int mx[maxn * maxn * 20];
int main(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> t[i];
	for(int i = 1; i <= n; i++) cin >> v[i];
	n += 2;
	for(int i = 0; i < n; i++) t[i] *= 2, v[i] *= 2;
	int sum = 0;
	for(int i = 0; i < n; i++) sum += t[i];
	for(int i = 0; i < sum; i++) mx[i] = 1<<30;
	int now = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= t[i]; j++){
			mx[now + j] = min(mx[now + j], v[i]);
		}
		now += t[i];
	}
	mx[0] = 0;
	mx[sum] = 0;
	for(int i = 0; i < sum; i++) if(i) mx[i] = min(mx[i], mx[i - 1] + 1);
	for(int i = sum - 1; i >= 0; i--) mx[i] = min(mx[i], mx[i + 1] + 1);
	double ans = 0;
	for(int i = 0; i < sum; i++) ans += mx[i] + mx[i + 1];
	cout << fixed << setprecision(12) << ans / 8.0 << endl;
	return 0;
}
