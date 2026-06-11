#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define BIP __builtin_popcount

const int B = 16;
const int N = 1<<B;

using namespace std;

int n, ord[N];
ll dp[N], a[B][B];

struct{
	bool operator()(int a, int b){
		return BIP(a) < BIP(b);
	}
} cmp;

int main(){

	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> a[i][j];
	}

	for(int i=0; i<(1<<n); i++) ord[i] = i;
	sort(ord, ord+(1<<n), cmp);

	for(int i=1; i<(1<<n); i++){
		int c = ord[i];
		vector<int> v;
		for(int j=0; j<n; j++) if((c>>j)&1) v.pb(j);
		int z = v.size();
		for(int j=1; j<(1<<(z-1)); j++){
			ll nc1 = 0, nc0 = 0;
			for(int k=0; k<z; k++){
				if((j>>k)&1) nc1 += 1<<v[k];
				else nc0 += 1<<v[k];
			}
			dp[c] = max(dp[c], dp[nc0]+dp[nc1]);
		}

		ll nsum = 0;
		for(int j=0; j<z; j++){
			for(int k=0; k<j; k++){
				nsum += a[v[j]][v[k]];
			}
		}

		dp[c] = max(dp[c], nsum);
	}

	cout << dp[(1<<n)-1] << endl;

	return 0;
}
