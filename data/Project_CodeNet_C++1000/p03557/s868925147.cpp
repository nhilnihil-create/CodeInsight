//q20.cpp
//Tue Aug 11 21:40:09 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	vector<ll> a(n);
	rep(i,n) cin >> a[i];

	vector<ll> b(n);
	rep(i,n) cin >> b[i];

	vector<ll> c(n);
	rep(i,n) cin >> c[i];

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());

	ll ans = 0;
	rep(i,n){
		ll mid = b[i];
		auto itrtop = upper_bound(c.begin(),c.end(),mid);
		ll top = c.end()-itrtop;
		auto itrbot = lower_bound(a.begin(),a.end(),mid);
		ll bottom;
		if (*itrbot == mid){
			if (itrbot==a.begin()){
				bottom = 0;
			}else {
				bottom = itrbot-a.begin();
			}
		}else {
			bottom = itrbot-a.begin();
		}
//		cout << top << " " << bottom << endl;
		ans += top*bottom;
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}