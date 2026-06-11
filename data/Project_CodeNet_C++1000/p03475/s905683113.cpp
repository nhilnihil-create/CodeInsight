#include<bits/stdc++.h>
using namespace std;
 
#define NL '\n'
#define xx first
#define yy second
#define ll long long
#define mp make_pair
#define pb push_back
#define sz(x) x.size()
#define all(x) (x).begin(), (x).end()
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;++i)
#define async() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 
#define FayeValentine 
void dbg(){cerr<<NL;}template<typename H,typename... T> void dbg(H h,T... t){cerr<<' '<<h;dbg(t... );}
#ifdef  FayeValentine
#define debug(...) cerr<<"("<<#__VA_ARGS__<<"):",dbg(__VA_ARGS__)
#else
#define debug(...) 
#endif



void absinthe() {
	ll n; cin >> n; n--;
	vector<ll> c(n), s(n), f(n);
	for(ll i = 0; i < n; i++) cin >> c[i] >> s[i] >> f[i];
	for(ll i = 0; i < n+1; i++) {
		ll t = 0;
		for(ll j = i; j < n; j++) {
			t = max(t, s[j]);
			ll tn = s[j];
			while(tn < t) tn += f[j];
			t = tn + c[j];
		}
		cout << t << NL;
	}	
}

 
int main(){
  async();
  int __t = 1, __c; //cin >> __t;
  for(__c = 1; __c <=__t; __c++) {
    //cout << "Case " << __c << ": "; 
    absinthe();
  }
}  
