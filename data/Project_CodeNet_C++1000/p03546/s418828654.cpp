#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define vll vector<ll>
#define vpll vector<pll>
#define eb emplace_back
#define MAX 999999999999999
int main(){
	ll n, m, ans = 0;
	cin >> n >> m;
	ll a[10][10], b;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			cin >> a[i][j];
		}
	}
	for (int k = 0; k < 10; k++){
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if (a[i][j] > a[i][k] + a[k][j]) a[i][j] = a[i][k] + a[k][j];
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> b;
			if (b == -1) continue;
			ans += a[b][1];
		}
	}
	printf("%lld\n", ans);
}