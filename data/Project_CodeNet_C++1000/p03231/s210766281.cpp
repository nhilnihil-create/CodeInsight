#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	ll N, M;
	string s, t;
	cin >> N >> M >> s >> t;
	ll g = __gcd(N, M);
	ll n = N/g;
	ll m = M/g;
	REP(i, 0, g){
		if(s[i*n] != t[i*m]){
			cout << -1;
			return 0;
		}
	}
	cout << (N*M)/g;

}
