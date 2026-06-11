#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;
int n, k;
int a[maxn];
int f[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),	cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	memset(f, 2e5, sizeof(f));
	f[0] = f[1] = 0, f[2] = abs(a[2] - a[1]);
	for(int i = 3; i <= n; ++i){
		for(int j = 1; j <= k; ++j){
			if(j >= i) break;
			f[i] = min(f[i], f[i-j] + abs(a[i]-a[i-j]));
		}
	}
	cout << f[n];
}