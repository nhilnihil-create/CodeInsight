#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n, a, b;

int main(void){
	cin >> n >> a >> b;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int x = i;
		int s = 0;
		while(x){
			s+=x%10;
			x/=10;
		}
		if(a <= s && s <= b) ans+=i;
	}
	cout << ans << endl;
	return 0;
}
