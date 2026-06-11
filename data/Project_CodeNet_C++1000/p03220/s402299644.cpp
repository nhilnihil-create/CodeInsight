#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

void solve(){
	int n;
	double t,a;
	cin >> n;cin >> t >> a;
	vector <int> h(n);
	for(int i = 0;i < n;++i) cin >> h[i];
	pair <double,int> minn = {2e18,-1};
	for(int i = 0;i < n;++i){
		double cc = t - 0.006 * h[i];
		if(abs(cc - a) < minn.first){
			minn.first = abs(cc - a);
			minn.second = i + 1;
		}
	}
	cout << minn.second << newl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
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
