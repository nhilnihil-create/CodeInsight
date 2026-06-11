#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <math.h>
#include <map>
#include <numeric>
#include <stack>
#include <queue>
#include <functional>
#include <stdio.h>
#define ll long long
#define pl pair<ll,ll>
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vvvl vector<vector<vector<ll> > >
#define vd vector<double>
#define vvd vector<vector<double> >
#define vvvd vector<vector<vector<double> > >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define vvvb vector<vector<vector<bool> > >
#define rep(i,a) for(ll i = 0;i<a;++i)
#define rep1(i,a) for(ll i = 1;i<a;++i)
#define rrep(i,a) for(ll i = a;i>=0;--i)
#define mod 1000000007
#define inf 10010010010
using namespace std;

//二分探索
bool solve(ll n, ll key){
	return n >= key;
}
//left,rightを半開区間で管理し、常にどちらか一方のみが真であるようにする
//デフォルトは与えられた配列でkey以上の最初の場所
ll binary_search(ll a, ll key){
	ll left = 0;
	ll right = a+1;
	while (right - left > 1){
		ll mid = left + (right - left) / 2;
		if (solve(mid, key)) right = mid;
		else left = mid;
	}
	return right;
}

int main(){
	string s; cin >> s;
	ll count = 0;
	ll ans = 0;
	rep(i, s.size()-1){
		if (s[i] == 'A') count++;
		else if (s[i] == 'B' && s[i + 1] == 'C'){
			ans += count;
			i++;
		}
		else count = 0;
	}
	cout << ans << endl;
	return 0;
}