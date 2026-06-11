#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	int n,h,w;
	cin >> n >> h >> w;

	cout << (n-h+1)*(n-w+1) << endl;

	return 0;
}