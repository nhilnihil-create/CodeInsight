#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

const lli mod = 1e9+7;

lli n;
string s;

lli modpow(lli a, lli x){
	lli ret = 1;
	while(x > 0){
		if(x&1){
			ret *= a;
			ret%=mod;
			x--;
		}else{
			a*=a;
			a%=mod;
			x >>= 1;
		}
	}
	return ret;
}

int main(void){
	cin >> n >> s;
	vector<lli> used(26);
	rep(i, n){
		used[s[i]-'a']++;
	}
	lli ans = 1;
	rep(i, 26){
		ans*=used[i]+1;
		ans%=mod;
	}
	ans--;
	if(ans < 0) ans*=mod;
	cout << ans << endl;
	return 0;
}
