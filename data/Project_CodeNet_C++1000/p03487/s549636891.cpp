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
	int n, tmp;
	cin >> n;
	unordered_map<int, int> m;
	REP(i, 0, n){
		cin >> tmp;
		++m[tmp];
	}
	ll ans = 0;
	for(auto it = m.begin(); it != m.end(); it++){
		if(it->F > it->S) ans += it->S;
		else ans += (it->S - it->F);
	}
	cout << ans;


}
