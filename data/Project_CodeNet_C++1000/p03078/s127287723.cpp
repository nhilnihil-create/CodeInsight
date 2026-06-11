#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;


int main(){
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<ll> a(x);
	vector<ll> b(y);
	vector<ll> c(z);
	vector<ll> d;
	for (int i = 0; i < x; i++){
		cin >> a[i];
	}
	for (int i = 0; i < y; i++){
		cin >> b[i];
	}
	for (int i = 0; i < z; i++){
		cin >> c[i];
	}
	sort(a.begin(), a.end(), greater<ll>());
	sort(b.begin(), b.end(), greater<ll>());
	sort(c.begin(), c.end(), greater<ll>());

	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			for (int l = 0; l < z; l++){
				if ((i+1)*(j+1)*(l+1) <= k) d.push_back(a[i]+b[j]+c[l]);
			}
		}
	}
	sort(d.begin(), d.end(), greater<ll>());
	for (int i = 0; i < k; i++){
		cout << d[i] << endl;
	}
	return 0;
 }

