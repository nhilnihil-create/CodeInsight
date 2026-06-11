#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main(){
	ll k, a, b, ef;
	ll ans;
	cin >> k >> a >> b;
	ef = b - a;
	if(ef <= 2 || a+1 > k){
		cout << 1+k << endl;
		return 0;
	}
	
	k -= a-1;
	ans = a;
	ans += ef*(k/2);
	if(k % 2 == 1){
		ans++;
	}
	
	cout << ans << endl;
	
}