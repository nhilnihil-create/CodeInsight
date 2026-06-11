#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;
int n;
int a[maxn], b[maxn], c[maxn];
int f[maxn][4];
int ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
	f[1][1] = a[1], f[1][2] = b[1], f[1][3] = c[1];
	for(int i = 2; i <= n; ++i){
		f[i][1] = max(f[i-1][2] + a[i], f[i-1][3] + a[i]);
		f[i][2] = max(f[i-1][1] + b[i], f[i-1][3] + b[i]);
		f[i][3] = max(f[i-1][1] + c[i], f[i-1][2] + c[i]);
	}
	for(int j = 1; j <= 3; ++j) ans = max(ans, f[n][j]);
	cout << ans;
}