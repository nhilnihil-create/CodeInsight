#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	vector<lli> a(n), b(n);
	lli suma, sumb;
	suma = sumb = 0;
	rep(i, n){
		cin >> a[i];
		suma += a[i];
	}
	rep(i, n){
		cin >> b[i];
		sumb += b[i];
	}
	lli ans = 0;
	if(sumb > suma) ans = -1;
	else{
		vector<lli> sub;
		lli comp = 0;
		rep(i, n){
			if(a[i] < b[i]){
				ans++;
				comp+=b[i]-a[i];
			}
			if(a[i] > b[i]){
				sub.push_back(a[i]-b[i]);
			}
		}
		sort(sub.begin(), sub.end(), greater<lli>());
		lli ssub = 0;
		rep(i, sub.size()){
			if(ssub >= comp) break;
			ssub += sub[i];
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
