#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

void solve(){
	int n,k;
	cin >> n >> k;
	long double ans = 0;
	long double p = 1.0 / n;
	if(n >= k){
		ans = (long double)(n - k + 1) / n;
		n = k - 1;
	}
	for(int i = 1;i <= n;++i){
		int t = 0;
		int num = i;
		while(num < k){
			num = num * 2;
			++t;
		}
		ans = ans + p * pow(0.5,t);
	}
	cout << ans << newl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(15);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
