#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define debug(x) cerr << #x << " : " << x << "\n"
typedef long long ll;
 
// code //


int main() {
	int n, mxNum = INT_MIN, minNum = INT_MAX;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;  i < n; ++i) {
		cin >> a[i];
		mxNum = max(mxNum, a[i]);
		minNum = min(minNum, a[i]);
	}
	
	cout << mxNum - minNum;
}
