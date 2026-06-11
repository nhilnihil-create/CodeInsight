#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<map>
//#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
int ans;
signed main() {
	int n, h, w; cin >> n >> h >> w;
	while (n--) {
		int a, b; cin >> a >> b;
		if (h <= a && w <= b)ans++;
	}
	cout << ans << endl;
}