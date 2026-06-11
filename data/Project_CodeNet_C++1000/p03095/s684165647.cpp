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
	ll n, m=pow(10, 9)+7;
	string s;
	cin >> n >> s;
	vi v(26,0);
	for(char c: s) ++v[c-'a'];
	ll ans = 1;
	REP(i, 0, 26){
		ans *= (v[i]+1);
		ans%= m;
	}
	cout << (ans-1)%m;
	

}
