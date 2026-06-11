#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll ZERO = 0;
const ll INF = 1e14;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;

ll gcd(ll a,ll b) {
	if(a == 0 || b == 0) {
		return max(a,b);
	}
	else {
		if(a < b) {
			ll tmp = a;
			a = b;
			b = tmp;
		}
		ll r = a % b;
		while(r != 0) {
			a = b;
			b = r;
			r = a % b;
		}
		return b;
	}
}

int main() {
    ll N,M;
    cin >> N >> M;
    string S,T;
    cin >> S >> T;
    ll G = gcd(N,M);
    ll n = N / G;
    ll m = M / G;
    bool ret = true;
    for(int i = 0;i < N;i++) {
        if(i * n >= N) {
            break;
        }
        else if(S.at(i * n) != T.at(i * m)) {
            ret = false;
        }
    }
    if(ret == true) {
        cout << N * M / G << endl;
    }
    else {
        cout << -1 << endl;
    }
}