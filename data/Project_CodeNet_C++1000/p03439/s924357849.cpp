#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
const ll INF = 1e18;
const ll MOD = 998244353;



int32_t main() {
	ios::sync_with_stdio(!cin.tie(NULL));

	int n;
	cin >> n;
	cout << 0 << endl;
	string tmp;
	map<string, int> mp;
	mp["Male"] = 0;
	mp["Female"] = 1;
	string vac = "Vacant";

	cin >> tmp;
	if(tmp == vac) return 0;

	int hi = n, lo = 0;
	int arr[2] = {mp[tmp], !mp[tmp]};
	int l = arr[0], r = arr[0];
	while(hi > lo){
		int mid = (hi + lo + 1) / 2;
		cout << mid << endl;
		cin >> tmp;
		if(tmp == vac)	return 0;
		if((mid - lo + 1)&1)	{
			if(l == mp[tmp])	lo = mid, l = mp[tmp];
			else	hi = mid, r = !mp[tmp];
		}
		else {
			if(l == !mp[tmp])	lo = mid, l = mp[tmp];
			else	hi = mid, r = !mp[tmp];
		}

	}
}

