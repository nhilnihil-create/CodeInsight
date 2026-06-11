#include<bits/stdc++.h>
using namespace std;
#define MAXN 200010

int a[MAXN];
int b[MAXN];

int a1[MAXN];
int b1[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n; i++)
		cin >> b[i];
	int ans = 0;
	for(int i = 0; i < 29; i++){
		int T = (1 << i);
		for(int i = 0; i < n; i++){
			a1[i] = (a[i]) % (T << 1);
			b1[i] = (b[i]) % (T << 1);
		}
		sort(a1, a1+n);
		sort(b1, b1+n);
		
		int cnt = 0;


		for(int i = 0; i < n; i++){
			cnt += (lower_bound(b1, b1+n, (T << 1) - a1[i]) - lower_bound(b1, b1+n, T - a1[i]));
			cnt += (lower_bound(b1, b1+n, (T << 2) - a1[i]) - lower_bound(b1, b1+n, 3*T - a1[i]));
		}
		if(cnt & 1)
			ans += (1 << i);
	}
	
	cout << ans << "\n";
	return 0;
}