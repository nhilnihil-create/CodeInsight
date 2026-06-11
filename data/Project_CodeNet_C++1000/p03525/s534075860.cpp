#include <iostream>
#include <cstring>
#include <string>    
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, d, cnt[13];
string str;

int main(){
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> d;
		cnt[d]++;
		if(d == 0 || cnt[d] > 2 || (d == 12 && cnt[d] > 1)){cout << 0 << endl; return 0;}
	}
	

	//if(n > 23){cout << 0 << endl; return 0;}
	if(n > 11){cout << 1 << endl; return 0;}	
	
	ll ans = 1;
	for(ll bit = 0; bit < (1 << n-1); bit++){
		vector<ll> v;
		v.push_back(0);

		ll itrb = 0;
		for(ll i = 1; i <= 12; i++){
			if(cnt[i] == 1){
				if(bit & (1 << itrb)){v.push_back(i);}
				else{v.push_back(-i);}
				itrb++;
			}
			if(cnt[i] == 2){
				v.push_back(i);
				v.push_back(-i);
				itrb++;
				itrb++;
			}
		}
		
		sort(v.begin(), v.end());
		ll ansbuf = 24;
		for(ll i = 1; i < v.size(); i++){
			ansbuf = min(v[i]-v[i-1], ansbuf);
		}
		ansbuf = min(min(v[v.size()-1]-v[0], 24 - (v[v.size()-1]-v[0])), ansbuf);
		ans = max(ansbuf, ans);
	}
	cout << ans << endl;
	return 0;
}