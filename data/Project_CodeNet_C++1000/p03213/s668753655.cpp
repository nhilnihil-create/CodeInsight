/*Flamenco Sketches*/
#include<bits/stdc++.h>
using namespace std;
 
#define NL '\n'
#define xx first
#define yy second
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define sz(x) x.size()
#define all(x) (x).begin(), (x).end()
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;++i)
#define async() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 
//#define FayeValentine 
void dbg(){cerr<<NL;}template<typename H,typename... T> void dbg(H h,T... t){cerr<<' '<<h;dbg(t... );}
#ifdef  FayeValentine
#define debug(...) cerr<<"("<<#__VA_ARGS__<<"):",dbg(__VA_ARGS__)
#else
#define debug(...) 
#endif


const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

void absinthe() {
	int n; cin >> n;
	int n2 = 0, n4 = 0, n14 = 0, n24 = 0, n74 = 0;
	for(int i = 0; primes[i] <= 97; i++) {
		int p = primes[i], cnt = 0;
		while(p <= n){
			cnt += n/p;
			p *= primes[i];
		}
		if(cnt >= 2) n2++;
		if(cnt >= 4) n4++;
		if(cnt >= 14) n14++;
		if(cnt >= 24) n24++;
		if(cnt >= 74) n74++;
	}
	debug(n2, n4, n14, n24, n74);
	int c1 = (n2-2) * ((n4*(n4-1))/2);
	int c2 = (n4-1) * n14;
	int c3 = (n2-1) * n24;
	int c4 = n74;
	debug(c1, c2, c3, c4);
	cout << c1 + c2 + c3 + c4 << NL;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  async();
  int __t = 1; //cin >> __t;
  for(int __c = 1; __c <=__t; __c++) {
    //cout << "Case #" << __c << ": "; 
    absinthe();
  }
}  