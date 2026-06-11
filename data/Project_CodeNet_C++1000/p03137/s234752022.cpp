#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int arr[m];
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + m);
	int sub[m - 1];
	for (int i = 0; i < m - 1; i++) {
		sub[i] = abs(arr[i + 1] - arr[i]);
	}
	sort(sub, sub + m - 1);
	int ans = 0;
	for (int i = 0; i < m - n ; i++)
		ans += sub[i];
	cout << ans << endl;
	return 0;
}
