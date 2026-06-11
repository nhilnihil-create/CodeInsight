/*
	Bakul Gaur (caesar1551)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PrePro ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr(i,n) for(ll i = 0; i < n; i++)
#define fre(i,a,b) for(ll i = a; i <= b; i++)
#define fb(i,n) for(ll i = n; i >= 0; i--)
#define fbe(i,a,b) for(ll i = a; i >= b; i--)
#define umap(x,y) unordered_map<x,y>
#define uset(x) unordered_set<x>
#define vv(x) vector<x>
#define pp(x,y) pair<x,y>
#define prar(a,n) fr(i,n){cout << a[i] << " ";}
#define inar(a,n) fr(i,n){cin >> a[i];}
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define mod 1000000007
#define MAX 301
inline ll gcd(ll a, ll b){
	if(b == 0){
		return a;
	}
	return gcd(b,a%b);
}
inline ll pwr(ll a, ll b, ll modulo = mod){
	if(a == 0 && b == 0){
		return 0;
	}
	ll ans = 1;
	while(b > 0){
		if(b&1){
			ans = ((ans%modulo) * (a%modulo))%modulo;
		}
		b >>= 1;
		a = ((a%modulo) * (a%modulo))%modulo;
	}
	return (ans+modulo)%modulo;
}
inline ll modInverse(ll a, ll p){
	// Only if p is prime.
	return pwr(a,p-2,p);
}



/* #############
   START SOLVING 
   ############# */

double dp[MAX][MAX][MAX];

double helper(ll &n, ll one, ll two, ll three){
	if(one < 0 || two < 0 || three < 0){
		return 0;
	}
	if(one == 0 && two == 0 && three == 0){
		return 0;
	}
	if(dp[one][two][three] > 0){
		return dp[one][two][three];
	}
	ll to_divide = one + two + three;
	double get_val = n + one*helper(n,one-1,two,three) + two*helper(n,one+1,two-1,three) + three*helper(n,one,two+1,three-1);
	return dp[one][two][three] = get_val/to_divide;
}

void solve(){
	ll n;
	cin >> n;
	ll one = 0, two = 0, three = 0;
	fr(i,n){
		ll num;
		cin >> num;
		if(num == 1){
			one++;
		}
		else if(num == 2){
			two++;
		}
		else{ 
			three++;
		}
	}
	memset(dp,-1,MAX*MAX*MAX*sizeof(double));
	cout << fixed << setprecision(10) << helper(n,one,two,three) << endl;
}

int main(){
	PrePro
	/* #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif */
    ll t = 1;
    // cin >> t;
    fr(i,t){
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    	// cout << endl;
    }
	return 0;
} 