#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, k; cin >> n >> k;
	long long a = 0, b = 0;
	long long ans = 0;
	for(int i = 1; i <= n; ++i) if(i % k == 0) a++;
	for(int i = 1; i <= n; ++i) if(i % k == k / 2) b++;
	ans = (k%2==0?1LL*a*a*a+b*b*b:1LL*a*a*a);
	cout << ans << endl;
}