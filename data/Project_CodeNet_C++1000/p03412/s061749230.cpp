//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define ins insert
#define er erase

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

const int oo = 1e18 + 7, mod = 1e9 + 7;

const int N = 2e5 + 5;

int n, a[N], b[N], c[N], ans;

signed main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 0; i < 29; i++){
	    for(int j = 1; j <= n; j++) c[j] = b[j] & ((1 << (i + 1)) - 1);
	    sort(c + 1, c + n + 1);
	    int tol = 0;
	    for(int j = 1; j <= n; j++){
	        //cout << c[j] << "\n";
	        int itr1 = lower_bound(c + 1, c + n + 1, (1 << (i + 1)) - (a[j] & ((1 << (i + 1)) - 1))) - c;
	        int itr2 = lower_bound(c + 1, c + n + 1, (1 << (i + 1)) + (1 << i) - (a[j] & ((1 << (i + 1)) - 1))) - c - 1;
	        int itr3 = lower_bound(c + 1, c + n + 1, (1 << i) - (a[j] & ((1 << (i + 1)) - 1))) - c - 1;
	        //cout << itr1 << " " << itr2 << " " << itr3 << "\n";
	        tol += n - itr3 - (itr2 - itr1 + 1);
	    }/*
	    int x = 0, y = 0;
	    for(int j = 1; j <= n; j++){
	        if(a[j] & (1 << i)) x++;
	        if(b[j] & (1 << i)) y++;
	    }
	    tol += n * n;
	    tol -= x * y;
	    tol -= (n - x) * (n - y);
	    */
	    //cout << i << " " << tol << "\n";
	    ans += (1 << i) * (tol & 1);
	}
	cout << ans;
}

