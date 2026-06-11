#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n, k;
	cin >> n >> k;
	ll s[n+1];
	s[0]=0;
	for(int i=1; i<=n; i++){
		ll a;
		cin >> a;
		s[i]=s[i-1]+a;
	}
	vector<ll> v;
	for(int i=0; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			v.push_back(s[j]-s[i]);
		}
	}

	ll ans=0;
	for(int i=59; i>=0; i--){
		vector<ll> tmp;
		for(int j=0; j<v.size(); j++){
			if(v[j]&(((ll)1)<<i)) tmp.push_back(v[j]);
		}

		if(tmp.size()>=k){
			ans+=(((ll)1)<<i);
			v=tmp;
		}
	}
	cout << ans << endl;

	return 0;
}