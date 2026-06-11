#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 3003;





ll dp[maxn][maxn];
//dp[i][j]: # of ways to build perm with elems [1,i], with j in last slot.

// if p[i-1]<p[i], merge with sum(dp[i-1][1]...dp[i-1][p[i]-1])
// if p[i-1]>p[i], merge with dp[i-1][p[i]] + sum(dp[i-1][p[i]+1]...dp[i-1][i-1])





// In the case that we picked a p[i] that already exists in i-1 prefix, then
// we have to "boost" previous elements to accommodate. Let's define a process
// for this. We will fix the current p[i] collision by boosting the other occurrence
// of p[i] by +1. If this causes another collision, we repeat this process (of
// boosting the other occurrence).


// It can be proven that by following this process, the set of "boosts" will
// uniquely determine the final permutation. In fact, this is necessary for
// the algorithm to be correct, otherwise we would overcount permutations.


// Suppose up to i-1, all permutations created by the above process are unique.
// Let's show that at ith element, we still will create permutations uniquely.

// In the case of no collision, the claim is obviously true.
// In the case of a collision, there's only one other p[i] in i-1th prefix,
// (otherwise i-1 prefix wouldn't be a permutation), so the resulting final
// permutation will be unique.




//<><>
//15342

int n;
string s;


void add(ll &x, ll y) {
    x %= mod;
    y %= mod;
    x += y;
    x %= mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>s;

    s="*"+s;
    dp[1][1]=1;

    for (int i=2; i<=n; i++) {
	
	for (int j=1; j<=i; j++) {
	    dp[i-1][j] += dp[i-1][j-1];
	    dp[i-1][j] %= mod;
	}

	
	for (int j=1; j<=i; j++) {
	    if (s[i-1]=='<') {
		ll acc=dp[i-1][j-1];
		dp[i][j] += acc;
	    }
	    if (s[i-1]=='>') {
		ll acc=dp[i-1][i]-dp[i-1][j-1];
		dp[i][j] += acc;
	    }
	    dp[i][j] %= mod;
	}
	// for (int b=1; b<=i; b++) {
	//     for (int a=1; a<=i-1; a++) {
	// 	//...a,b
	// 	int real_a = a;
	// 	if (a>=b) real_a++;
	// 	assert(real_a!=b);
	// 	if ((real_a<b) != (s[i-1]=='<')) {
	// 	    continue;
	// 	}
	// 	add(dp[i][b], dp[i-1][a]);
	//     }
	// }
    }


    ll res = 0;
    for (int j=1; j<=n; j++) {
	add(res, dp[n][j]);
    }
    res %= mod;
    res += mod;
    res %= mod;
    cout<<res<<endl;

    return 0;
}
