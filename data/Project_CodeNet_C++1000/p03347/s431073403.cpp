#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	ll a[n+1];
	for(int i=0; i<n; i++) cin >> a[i];
	a[n]=0;

	bool flg=(a[0]!=0);
	for(int i=1; i<=n; i++){
		flg|=(a[i]>a[i-1]+1);
	}
	if(flg){
		cout << -1 << endl;
		return 0;
	}

	ll ans=0;
	map<ll, ll> cnt;
	for(int i=1; i<=n; i++){
		if(a[i]<a[i-1]){
			ans+=a[i-1];
			for(int j=a[i-1]; cnt[j]!=0; j--){
				ans+=(cnt[j]-1)*j;
			}
			cnt.clear();
		}
		cnt[a[i]]++;
	}
	cout << ans << endl;
	return 0;
}