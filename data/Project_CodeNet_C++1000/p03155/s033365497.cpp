#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
//#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define mp make_pair
#define all(x) x.begin(),x.end()
#define puts(x) cout << x << endl
using namespace std;
int input() {
	int r;
	cin >> r;
	//scanf("%lld", &r);
	return r;
}
signed main() {
	int h, w, n; cin >> n >> w >> h;
	cout << (n - w + 1) * (n - h + 1) << endl;
}