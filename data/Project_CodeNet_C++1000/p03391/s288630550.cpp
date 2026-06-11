#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int maxn = 2e5 + 10;
const int inf = 1e9;

pii arr[maxn];

int main () {
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	
	bool found = 0;
	int mn = inf;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].F >> arr[i].S;
		sum += arr[i].F;
		if (arr[i].F > arr[i].S) {
			found = 1;
			mn = min (mn, arr[i].S);
		}
	}
	
	if (!found)
		return cout << 0 << endl, 0;
	cout << sum - mn << endl;
}
