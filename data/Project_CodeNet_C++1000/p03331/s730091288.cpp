#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int f(int a){
	int ans = 0;
	while(0 < a){
		ans += a%10;
		a /= 10;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;

	int ans = 1000000;
	for(int i = 1; i < n; i++){
		int a = f(i);
		int b = f(n-i);
		ans = min(ans, (a+b));
	}
	cout << ans << endl;
}