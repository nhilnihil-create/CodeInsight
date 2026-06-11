#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll n;
	cin >> n;
	vector<ll> a(0);
	for(int i=0; i>=0; i++){
		ll b = pow(2, i) * (1-i%2*2);
		a.push_back(b);
		if(b > 400000000000 || b < -400000000000) break;
	}
	if(n == 0){
		cout << 0 << endl;
		return 0;
	}else if(n < 0){
		rep(i, a.size()) a.at(i) *= -1;
		n *= -1;
	}
	vector<int> b(64);
	rep(i, 64){
		if(n == 0) break;
		b.at(i) = n%2;
		n /= 2;
	}
	rep(i, 64){
		if(b.at(i) == 1 && a.at(i) < 0) b.at(i+1)++;
	}
	for(int j=0; j<=2; j++){
		int f = 0;
		rep(i, 64){
			if(b.at(i) == 2){
				f = 1;
				if(b.at(i+1) == 1){
					b.at(i) = 0;
					b.at(i+1) = 0;
				}else{
					b.at(i) = 0;
					b.at(i+1)++;
					b.at(i+2)++;
				}
			}
		}
		if(f == 0) break;
	}
	int k = 0;
	rep(i, 64) if(b.at(i) == 1) k = i;
	rep(i, k+1){
		cout << b.at(k-i);
	}
	cout << endl;
	return 0;
}