#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 22;


int n;
int g[maxn][maxn];


void add(ll &x, ll y) {
    x%=mod;
    y%=mod;
    x+=y;
    x%=mod;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;
    for (int i=0; i<n; i++) {
	for (int j=0; j<n; j++) {
	    cin>>g[i][j];
	}
    }

    vector<ll> dp(1<<n, 0);//ways to match mask of women
    dp[0]=1;
    
    for (int mask=0; mask<(1<<n); mask++) {
	int i = __builtin_popcount(mask);
	//i men have been used so far, so we're on ith man 0-indexed
	for (int j=0; j<n; j++) {
	    if (!(mask>>j&1)) {
		if (g[i][j]) {
		    add(dp[mask|(1<<j)], dp[mask]);
		}
	    }
	}
    }
    

    ll res = dp[(1<<n)-1];
    res%=mod;
    res+=mod;
    res%=mod;
    cout<<res<<endl;

    return 0;
}
