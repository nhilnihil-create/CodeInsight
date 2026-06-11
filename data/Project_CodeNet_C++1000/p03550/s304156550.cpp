#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, z, w, a[2001]; cin >> n >> z >> w;
	for(int i=1;i<=n;i++) cin >> a[i];

	if(n >= 2) cout << max(abs(a[n] - w), abs(a[n] - a[n-1]));
	else cout << abs(a[n] - w);
}