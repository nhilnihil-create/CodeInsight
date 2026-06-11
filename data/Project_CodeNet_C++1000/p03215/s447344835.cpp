//dwango5_b.cpp
//Sat Sep 21 09:19:23 2019

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
	int n,k;
	cin >> n >> k;

	ll a[n];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}

	vector<ll> beaut;
	for (int i=0;i<n;i++){
		ll tempsum = 0;
		for (int j=i;j<n;j++){
			tempsum = tempsum+a[j];
			beaut.push_back(tempsum);
		}
	}

	ll ans = 0;
	for (int i=40;i>=0;i--){
		int count = 0;
		ll check = 1LL<<i;
		for (int j=0;j<beaut.size();j++){
//			cout << (beaut[j] & (ans+check)) << endl;
			if ((beaut[j] & (ans+check)) == (ans+check)){
				count++;
				if (count == k){
					ans += check;
					break;
				}
			}
		}
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}