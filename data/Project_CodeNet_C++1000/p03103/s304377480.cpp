#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
#include <iomanip>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	pair<ll, ll> a[n];
	for(ll i=0; i<n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a, a+n);
	ll ans = 0;
	for(ll i=0; m!=0; i++){
		if(a[i].second <= m){
			m-=a[i].second;
			ans += a[i].first*a[i].second;
		}
		else if(a[i].second > m){
			ans += a[i].first *m;
			m -= m;
		}
	}
	cout << ans;
	return 0;
}