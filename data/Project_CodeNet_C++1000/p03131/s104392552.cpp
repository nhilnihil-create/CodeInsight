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
	ll k, a, b, ans=1;
	cin >> k >> a >> b;
	if(b <= a+1) ans = k+1;
	else{
		ans = a;
		k -= (a-1);
		if(k % 2 == 0) ans += (k/2 * (b-a));
		else ans += (k/2 * (b-a)) + 1;
	}
	cout << ans;

}
