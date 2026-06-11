#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	vector<ll> c;
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	ll sum=0;
	ll num=0;
	rep(i,n){
		if(b[i]>a[i]) {
			sum+=b[i]-a[i];
			num++;
		}
		if(a[i]>b[i]){
			c.push_back(a[i]-b[i]);
		}
	}
	sort(c.begin(),c.end(),greater<int>());
	if(sum>0){
		for(int i=0;i<c.size();i++){
			sum-=c[i];
			num++;
			if(sum<0) break;
		}
	}
	if(sum>0) cout << -1 << endl;
	else cout << num << endl;
	return 0;
}

