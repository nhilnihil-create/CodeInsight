#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int calc(int num){
	int ans=0;
	while(num>0){
		ans+=num%10;
		num/=10;
	}
	return ans;
}

int main() {
	int n; cin >> n;
	int ans=n;
	for(int i=1; i<n; i++){
		ans = min(ans, calc(i)+calc(n-i))	;
	}
	cout << ans << endl;
}

