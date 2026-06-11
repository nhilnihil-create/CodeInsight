#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll M, K;
	cin >> M >> K;

	if(K >= (1<<M)) {
		cout << -1 << endl;
		return 0;
	}

	if (M == 1) {
		if(K == 1) {
			cout << -1 << endl;
			return 0;
		}
		cout << "0 0 1 1" << endl;
		return 0;
	} else {

		rep(i, (1<<M)) {
			if(i == K)continue;
			cout << i << " ";
		}
		cout << K << " ";
		for(ll i = (1<<M) - 1; i >= 0; i--) {
			if(i == K)continue;
			cout << i << " ";
		}
		cout << K << endl;;
	}
}
