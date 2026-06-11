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

int fun(pair<string ,int> & u ,pair<string , int> & v) {
	if(u.F == v.F) {
		return u.S > v.S;
	}
	else {
		return u.F < v.F;
	}
}
 
void solve()
{
	int n;
	
	cin >> n;
	
	vector<pair<string , int>> a(n);
	
	map<int , int> id;
	
	for(int i = 0; i < n; ++i) {
		cin >> a[i].F >> a[i].S;
		id[a[i].S] = i+1;
	}
	
	sort(ALL(a) , fun);
	
	for(int i = 0; i < n; ++i) {
		cout << id[a[i].S] << endl;
	}
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
