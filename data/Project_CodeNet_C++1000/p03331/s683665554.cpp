#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, ans = 1e9;

int calc(int x) {
	int res = 0;
	while(x) {
		res += x%10;
		x /= 10;
	}
	return res;
}

int main() {
	cin>>n;
	for(int i = 1; i < n; i++) 
		ans = min(calc(i) + calc(n - i), ans);
	cout<<ans<<endl;
	return 0;
}