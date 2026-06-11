	#include <iostream>
	#include <string>
	#include <vector>
	#include <algorithm>
	#include <utility>
	#include <map>
	using namespace std;
	typedef long long ll;
	#define rep(i,n) for (int i=0;i < (int)(n);i++)


	int main(){
		int n;
		ll k;
		cin >> n >> k;
		vector<ll> v(n);
		rep(i,n) cin >> v[i];

		ll res = 0;

		for (int kdigit = 60; kdigit >= -1;kdigit--){
			if (kdigit != -1 && !(k & (1LL<<kdigit))) continue;

			ll tmp = 0;
			for (int xdigit = 60; xdigit >= 0;xdigit--){
				ll mask = 1LL << xdigit;
				int num = 0;
				rep(i,n) if (v[i] & mask) num++;

				if (xdigit > kdigit){
					if (k & mask) tmp += mask * (n-num);
					else tmp += mask *num;
				}
				else if (xdigit == kdigit){
					tmp += mask * num;
				}
				else {
					tmp += mask * max(num,n-num);
				}
			}
			res =max(res,tmp);
		}
		cout << res << endl;
		return 0; 
	}

