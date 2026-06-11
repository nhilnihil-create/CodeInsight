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
	int n;
	ll ans = 1, mod=pow(10, 9) + 7;
	string s;
	cin >> n >> s;
	unordered_map<char, int> m;
	REP(i, 0, n) ++m[s[i]];
	
	for(auto it = m.begin(); it != m.end(); it++){
		ans *= (it->S+1);
		ans %= mod;
	}
	cout << ans-1;

}
