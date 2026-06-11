#include<bits/stdc++.h>

using namespace std;
using   ll=long long;

#define fast        	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define endl        	"\n"
#define pb          	push_back
#define mp          	make_pair
#define F           	first
#define S           	second
#define int             long long int
#define pll				pair<int , int>

#define ALL(v)      	v.begin(),v.end()
#define ALLR(v)     	v.rbegin(),v.rend()
#define pii         	3.14159265358979323
#define inf     		LLONG_MAX
#define ones(x)     	__builtin_popcount(x)
#define fill(a,b)   	memset(a,b,sizeof(a))
#define mod 			1000000007
#define hell            998244353 

ll mod_pow(ll a,ll b,ll m) 
{
    ll res = 1;
    while(b)	
    {
        if(b&1) 	
        {
        	res=(res*a) % m;
        }
        a=(a*a) % m;
        b>>=1;
    }
    return res;
}

ll mod_inverse(ll a) 
{
	return mod_pow(a , mod-2 , mod);
}
 
void solve()
{
	int n;
	
	cin >> n;
	
	int a[n];
	
	int cnt = 0;
	
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	sort(a , a+n);
	
	int p[n+1] {};
	int s[n+1] {};
	
	for(int i = 0; i < n; ++i) {
		if(i == 0) {
			p[i] = a[i];
			continue;
		}
		
		p[i] = __gcd(p[i-1] , a[i]);
	}
	
	for(int i = n-1; i >= 0; --i) {
		if(i == n-1) {
			s[i] = a[i];
			continue;
		}
		
		s[i] = __gcd(s[i+1] , a[i]);
	}
	
	int mx = 0;
	
	for(int i = 0; i < n; ++i) {
		if(i == 0) {
			mx = max(mx , s[i+1]);
		}
		else if(i == n-1) {
			mx = max(mx , p[i-1]);
		}
		else {
			mx = max(mx , __gcd(p[i-1] , s[i+1]));
		}
	}
	
	cout << mx;
}

signed main() {
    fast;
    
    int t = 1;
    
	//cin >> t;
    
    while(t--) {
        solve();
    }
 
    return 0;
}
