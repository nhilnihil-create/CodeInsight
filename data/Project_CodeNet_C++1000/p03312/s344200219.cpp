#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n),sum(n,0LL);
	for(int i = 0; i < n; i++){
		cin>>a[i];
		sum[i] = (i==0?0:sum[i-1]) + a[i];
	}

	vector<int> half_left(n,0);
	int half_pos = 0;
	for(int i = 1; i < n-2; i++){
		ll P = sum[half_pos];  // P = 0 ~ half_pos
		ll Q = sum[i] - sum[half_pos]; //Q = half_pos+1 ~ i
		while(abs(P + a[half_pos+1] - (Q-a[half_pos+1])) < abs(P-Q)){
			half_pos++;
			P = sum[half_pos];
			Q = sum[i] - sum[half_pos];
		}

		half_left[i] = half_pos;
	}

	vector<int> half_right(n,0);
	half_pos = n-1;
	for(int i = n-3; i >=1; i--){
		ll R = sum[half_pos-1] - sum[i];  // R = i ~ half_pos-1
		ll S = sum[n-1] - sum[half_pos-1];	// S = half_pos ~ n-1
		while(abs(R - a[half_pos-1] - (S + a[half_pos-1]))< abs(R-S)){
			half_pos--;
			R = sum[half_pos-1] - sum[i];
			S = sum[n-1] - sum[half_pos-1];
		}

		half_right[i] = half_pos;
	}

	// for(int i = 1; i < n-2; i++){
	// 	cout << i << " " << a[half_left[i]] << " "<<a[half_right[i]] << endl;
	// }

	ll ans = INF*INF;
	for(int i = 1; i < n-2; i++){
		ll P = sum[half_left[i]], Q = sum[i] - sum[half_left[i]];
		ll R = sum[half_right[i]-1] - sum[i], S = sum[n-1] - sum[half_right[i]-1];

		ll ma = max(max(P,Q),max(R,S));
		ll mi = min(min(P,Q),min(R,S));
		ans = min(ans,abs(ma-mi));
	}

	cout<<ans<<endl;

	return 0;
}