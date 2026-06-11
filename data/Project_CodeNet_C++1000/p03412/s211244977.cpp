//arc092_d.cpp
//Mon Jan 27 11:24:03 2020

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
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	vector<ll> a,b;
	a.resize(n);
	b.resize(n);
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	for (int i=0;i<n;i++){
		cin >> b[i];
	}

	ll ans = 0;
	for (int i=29;i>=0;i--){
		ll bekihigh = 1<<(i+1);
		ll bekilow = 1<<i;
		for (int j=0;j<n;j++){
			a[j] = a[j]%bekihigh;
			b[j] = b[j]%bekihigh;
		}
		sort(b.begin(),b.end());
		ll keta = 0;
		for (int j=0;j<n;j++){
			if (bekilow-a[j]>=0){
				keta += lower_bound(b.begin(),b.end(),bekihigh-a[j])
						- lower_bound(b.begin(),b.end(),bekilow-a[j]);
			}else {
				keta += lower_bound(b.begin(),b.end(),bekihigh-a[j])-b.begin();
				keta += lower_bound(b.begin(),b.end(),bekihigh)
						- lower_bound(b.begin(),b.end(),bekihigh+bekilow-a[j]);
			}
		}
		if (keta%2==1){
			ans += bekilow;
		}
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}