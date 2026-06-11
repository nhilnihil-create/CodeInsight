#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
ll n, res;
map<string, ll> mpm, mpu;
string str, mae, ush, rev, nat;

void dfsa(ll x, ll y) {
	if (x == n) {
		mpm[nat + rev + to_string(y)]++;
	} else {
	    nat += mae[x];
	    dfsa(x + 1, y + 1);
	    nat.pop_back();
		rev = mae[x] + rev;
		dfsa(x + 1, y);
		rev.erase(rev.begin());
	}
}

void dfsb(ll x, ll y) {
	if (x == n) {
		mpu[nat + rev + to_string(y)]++;
	} else {
		nat += ush[n - 1 - x];
		dfsb(x + 1, y + 1);
		nat.pop_back();
		rev = ush[n - 1 - x] + rev;
		dfsb(x + 1, y);
		rev.erase(rev.begin());
	}
}

int main(void) {
	cin >> n >> str;
	mae = str.substr(0, n);
	ush = str.substr(n, n);
	dfsa(0, 0);dfsb(0, 0);
	for (auto itr = mpm.begin(); itr != mpm.end(); ++itr) {
		res += itr->second * mpu[itr->first];
	}
	cout << res << endl;
}
