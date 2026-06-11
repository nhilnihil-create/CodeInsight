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
	ll n, m, c;
	cin >> n >> m >> c;
	ll b[m];
	ll a[n][m];
	for(ll i=0; i<m; i++)
		cin >> b[i];
	ll ans = 0, cur = 0;
	for(ll i=0; i<n; i++){
		for(ll j=0; j<m; j++){
			cin >> a[i][j];
			cur += a[i][j]*b[j];
		}
		if(cur + c > 0)
			ans++;
		cur = 0;
	}
	cout << ans;
	return 0;
}