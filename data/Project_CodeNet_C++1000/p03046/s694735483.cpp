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
	int m, k; cin >> m >> k;
	if(m == 1) {
		if(k == 0) cout << "0 0 1 1" << NL;
		else cout << -1 << NL;
		return;
	}
	if((1<<(m)) <= k) {
		cout << -1 << NL;
		return;
	}
	for(int i = 0; i < (1<<m); i++) {
		if(i == k) continue;
		cout << i << " ";
	}
	cout << k << " ";
	for(int i = (1<<m)-1; i >= 0; i--) {
		if(i == k) continue;
		cout << i << " ";
	}
	cout << k;
}
 
 
int main(){
  async();
  int __t = 1, __c; //cin >> __t;
  for(__c = 1; __c <=__t; __c++) {
    //cout << "Case " << __c << ": "; 
    absinthe();
  }
}  