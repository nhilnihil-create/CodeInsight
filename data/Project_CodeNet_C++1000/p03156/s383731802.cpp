
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

	int n, a, b;
	cin >> n >> a >> b;
	int one = 0, two = 0, three = 0;
	int ans = 0;
	rep(i, n){
		int p;
		cin >> p;
		if(p <= a){
			one++;
		}
		else if(p <= b){
			two++;
		}
		else{
			three++;
		}
		ans = min({one, two, three});
	}

	cout << ans << endl;


    return 0;
}
