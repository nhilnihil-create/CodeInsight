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
			int iter1t = lower_bound(b.begin(),b.end(),bekilow-a[j])-b.begin();
			int iter2t = lower_bound(b.begin(),b.end(),bekilow*2-a[j])-b.begin();
			int iter3t = lower_bound(b.begin(),b.end(),bekilow*3-a[j])-b.begin();
			int iter4t = lower_bound(b.begin(),b.end(),bekilow*4-a[j])-b.begin();
			keta += (iter2t-iter1t)+(iter4t-iter3t);
		}
		if (keta%2==1){
			ans += bekilow;
		}
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}