#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;



typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

ll n,f[100][10],p[100][11];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 10; j++){
			cin >> f[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 11; j++){
			cin >> p[i][j];
		}
	}

	ll ans = -(1<<30);

	for(int bit = 1; bit < (1<<10); bit++){
		ll x = 0;
		for(int i = 0; i < n; i++){
			int cnt = 0;
			for(int j = 0; j < 10; j++){
				if((bit>>j&1) && f[i][j]) cnt++;
			}
			x += p[i][cnt];
		}
      
      
		if(ans<x) ans = x;
	}
	cout << ans << endl;

	return 0;
}