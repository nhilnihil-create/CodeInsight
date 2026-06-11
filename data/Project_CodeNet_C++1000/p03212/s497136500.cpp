#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll n;
	cin >> n;
	ll n0 = n;
	int k = 0;
	while(n0 != 0){
		n0 /= 10;
		k++;
	}
	ll ans = 0;
	int t = pow(4, 3);
	vector<int> b(4);
	b.at(0) = 0;
	b.at(1) = 3;
	b.at(2) = 5;
	b.at(3) = 7;
	for(int i=0; i>=0; i++){
		int n1 = i;
		vector<int> a(4);
		rep(i, 4) a.at(i) = 0;
		ll kl = 0;
		rep(i, k+1){
			a.at(n1%4)++;
			kl += b.at(n1%4)*pow(10, i);
			n1 /= 4;
			if(n1 == 0) break;
		}
		if(kl > n) break;
		int f = 0;
		if(a.at(0) != 0) f = 1;
		rep(i, 3) if(a.at(i+1) == 0) f = 1;
		if(f == 0) ans++;
/*		rep(i, 4) cout << a.at(i) << ' ';
		cout << ':' << kl << ' ' << f;
		cout << endl;
*/	}
	cout << ans << endl;
	return 0;
}
