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
void dz(){cerr<<NL;}template<typename H,typename... T> void dz(H h,T... t){cerr<<' '<<h;dz(t... );}
#ifdef  FayeValentine
#define debug(...) cerr<<"("<<#__VA_ARGS__<<"):",dz(__VA_ARGS__)
#else
#define debug(...) 
#endif

void absinthe() {
	int n, k; cin >> n >> k;
	ll sum = 0;
	for(ll i = k+1; i <= n; i++) {
		ll el = (i-k), d = n/i;
		ll cur_sum = el*d;
		if(n%i!=0) {
			ll ex = n-(d*i);
			if(ex >= k) cur_sum += (ex - k + 1);
			if(k == 0) cur_sum--;	
		}
		sum += cur_sum;
	}
	cout << sum << NL;

}
 
int main(){
  async();
  int __t = 1, __c; //cin >> __t;
  for(__c = 1; __c <=__t; __c++) {
    //cout << "Case " << __c << ": "; 
    absinthe();
  }
}  