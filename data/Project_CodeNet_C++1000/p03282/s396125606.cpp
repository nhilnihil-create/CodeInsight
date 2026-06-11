#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (int i = 0; i < (ll)(n); ++i)
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	string s; cin >> s;
	int k; cin >> k;
	for(int i=0;i<k;i++) {
		if(s[i]!='1') {
			cout << s[i] << endl;
			return 0;
		}
	}
	cout << 1 << endl;
}