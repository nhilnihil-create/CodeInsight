#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using PL = pair<ll,ll>;


int main()
{
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<ll> a(x), b(y), c(z);
	for(int i = 0; i < x; i++)cin >> a[i]; sort(a.begin(), a.end(), greater<ll>());
	for(int i = 0; i < y; i++)cin >> b[i]; sort(b.begin(), b.end(), greater<ll>());
	for(int i = 0; i < z; i++)cin >> c[i]; sort(c.begin(), c.end(), greater<ll>());

	vector<ll> arr;
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++) {
			for(int t = 0; t < z; t++) {

				if((i + 1) * (j + 1) * (t * 1) > k + 10)break;
				else arr.emplace_back(a[i] + b[j] + c[t]);
			}
		} 
	}
	sort(arr.begin(), arr.end(), greater<ll>());
	for(int i = 0; i < k; i++)cout << arr[i] << endl;

}