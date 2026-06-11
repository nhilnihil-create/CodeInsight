#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli x;

int main(void){
	cin >> x;
	lli ans = 0;
	for(int i = 1; i < 40; i++){
		lli b = i;
		for(int j = 0; j < 10; j++){
			b*=i;
			if(b > x) break;
			ans = max(ans, b);
		}
	}
	cout << ans << endl;
	return 0;
}
