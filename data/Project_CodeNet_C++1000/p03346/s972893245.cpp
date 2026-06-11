#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 123;
int n, a[N], s[N], ans;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		s[a[i]] = s[a[i] - 1] + 1; 
		ans = max(ans, s[a[i]]);
	}
	cout << n - ans;
}