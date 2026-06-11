#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(long long i = 0;i < (n);i++)
using ll = long long;
using vl = vector<long long>;
using P = pair<long long,long long>;

int main(){
	ll x,y; cin >> x >> y;
	ll ans = 0;
	while(y >= x){
		x *= 2;
		ans++;
	}
	cout << ans << endl;
}