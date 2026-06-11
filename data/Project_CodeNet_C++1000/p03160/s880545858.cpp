#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;
int n;
int a[maxn];
int f[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	memset(f, 0x3f, sizeof(f));
	f[0] = f[1] = 0, f[2] = abs(a[2] - a[1]);
	for(int i = 3; i <= n; ++i){
		f[i] = min(f[i], f[i-1] + abs(a[i] - a[i-1]));
		f[i] = min(f[i], f[i-2] + abs(a[i] - a[i-2]));
	}
	cout << f[n];
}