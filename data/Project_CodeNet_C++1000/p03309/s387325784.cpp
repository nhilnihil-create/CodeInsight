#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using ll = long long;

using namespace std;

const int inf = 1e6 + 7;

int main(){	
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++)cin >> a[i];
	
	vector<ll> b(n);
	for(int i = 0; i < n; i++){
		b[i] = (a[i] - (i + 1));
	}
	
	sort(b.begin() , b.end());
	
	ll c;
	if(n % 2 == 1){
		c = b[n / 2];
	}else{
		c = b[n / 2] + b[n / 2 - 1];
		c /= 2;
	}
	
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += abs(b[i] - c);
	}
	cout << ans << endl;
	return 0;
}
 