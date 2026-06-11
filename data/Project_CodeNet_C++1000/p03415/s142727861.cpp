#include<bits/stdc++.h>
#include<numeric>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i <= (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	char c;
	rep(i,3){
		rep(j,3){
			cin >> c;
			if(i==j)
				cout << c;
		}
	}
	cout << endl;

	return 0;
}