#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
#define MOD9 998244353
#define intMAX 51000;
#define PI 3.14159265359
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int main(){
	int N, T;
	cin >> N >> T;
	vector<int> c(N);
	vector<int> t(N);
	int ans = intMAX;
	for(int i=0; i<N; ++i) cin >> c[i] >> t[i];
	for(int i=0; i<N; ++i){
		if(t[i] <= T) ans = min(ans, c[i]);
	}
	if(ans == 51000) cout << "TLE" << endl;
	else cout << ans << endl;
}