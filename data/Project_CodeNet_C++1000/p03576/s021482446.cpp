#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#define PI 3.14159265359
typedef long long ll;
const int MOD = 1e9+7;
const ll LLINF = 7e18;
using namespace std;


ll llmin(ll x, ll y){
	if (x < y) return x;
	return y;
}

ll llmax(ll x, ll y){
	if (x > y) return x;
	return y;
}



int main(){
	int n, o;
	cin >> n >> o;
	vector<pair<ll, ll> > xy(n);
	for (int i = 0; i < n; i++){
		cin >> xy[i].first >> xy[i].second;
	}

	ll ans = LLINF;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				for (int l = 0; l < n; l++){
					ll xmax = llmax(llmax(xy[i].first, xy[j].first), llmax(xy[k].first, xy[l].first));
					ll xmin = llmin(llmin(xy[i].first, xy[j].first), llmin(xy[k].first, xy[l].first));
					ll ymax = llmax(llmax(xy[i].second, xy[j].second), llmax(xy[k].second, xy[l].second));
					ll ymin = llmin(llmin(xy[i].second, xy[j].second), llmin(xy[k].second, xy[l].second));
					int tmp = 0;
					for (int m = 0; m < n; m++){
						if (xmin <= xy[m].first && xy[m].first <= xmax && ymin <= xy[m].second && xy[m].second <= ymax){
							tmp++;
						}
					}
					if (tmp >= o){
						ans = llmin(ans, (xmax-xmin)*(ymax-ymin));
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
