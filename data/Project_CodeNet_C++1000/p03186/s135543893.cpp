#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <bitset> 
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
 
#define int long long
#define ll long long 
#define F first
#define sqr(x) ((x) * (x))
#define S second
#define make make_pair
#define pb push_back
#define sz(x) (ll)(x.size()) 
#define all(x) x.begin (), x.end ()

using namespace std;
                        
typedef unsigned long long ull;
typedef long double ld;

const int MOD = (int)1e9 + 7;
const int N = (int)2e6+ 222;
const ll INF = (ll)1e18;
const double eps = (double)1e-6;


int a, b, c;

void solve () {
	int sum = 0;
	cin >> a >> b >> c;
	if (b + a >= c - 1) cout << b + c;
	else {
		cout << b + (b + a + 1);
	

	}	
}

signed main () {
    #ifdef Maga
        freopen("input", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);                                              
    int t = 1;
    while (t --) {
    	solve ();
    }
    return 0;
}



