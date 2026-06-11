#include <bits/stdc++.h>
 
#define se second
#define sz(x) (int)(x.size())
#define ll long long
#define rep(i,x,y) for(int i = x; i <= y; ++i)
#define repr(i,x,y) for(int i = x; i >= y; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define ull unsigned ll
 
#define pi 3.14159265358979
 
using namespace std;
 
const int N = (int)(1e6) + 322;
const ll INF = 2e18 + 17;
const int inf = 2e9;
const int mod = 1000000007;
const double eps = 1e-9;
 
int gcd(int a, int b) { return b ? gcd (b, a % b) : a; }
 
int nbr_bits(int a){
	return log2(a)+1;
}
 
 
int binpow(int a, int n, int mod) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        n >>= 1;
    }
    return res;
}

int fastpow(int a, int n, int mod) {
    if(n==0)
    	return 1;
    if(n%2==0){
    	int res = fastpow(a,n/2,mod);
    	res*=res;
    	res%=mod;
    	return res;
	}
	int res = (fastpow(a,n-1,mod)*a)%mod;
	return res;
    
}
 
// ---------------------------------------------------- 
 
signed main()
{

	int n, k;
	cin >> n >> k;
	int sum = n*3 + k;
	cout << sum / 2 << endl;
	return 0;
}
	