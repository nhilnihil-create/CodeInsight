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
const int MOD1 = (int)1e9 + 9;
const int N = (int)2e6+ 222;
const ll INF = (ll)1e18;
const int p = 997, p1 = 991;
const double eps = (double)1e-6;
     
int a[N];
int m, k;
int used[N];

int lg2 (int x) {
	int res = 0;
	while (x) {
		res ++;
		x /= 2;
	}
	return res - 1;
}
             
void solve () {                                                
	cin >> m >> k;
	if (m == 1 && k != 0) {
		cout << -1;
		return;
	}
	if (k == 0) {
		int pos = 0;
		for (int i = 1; i <= (1 << (m + 1)); i += 2) {
			cout << pos << " " << pos << " ";
			pos ++;		
       	}
       	return;
	}
	if ((1 << m) - 1 < k) {
		cout << -1;
		return;	
	}
	
	cout << 0 << " " << k << " " << 0 << " ";
	for (int i = 1; i <= (1 << m) - 1; ++i) {
		if (k != i) cout << i << " ";
	}	
	cout << k << " ";
	for (int i = (1 << m) - 1; i >= 1; --i) {
		if (k != i) cout << i << " ";
	}
}


signed main () {
    #ifdef Maga
        //freopen("input", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);                                              
    int t = 1;
    while (t --) {
    	solve ();
    }
    return 0;
}



