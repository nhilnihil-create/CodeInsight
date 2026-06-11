
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

	int n, k;
	cin >> n >> k;

	if(n >= k && (n+1) / 2 >= k){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}
