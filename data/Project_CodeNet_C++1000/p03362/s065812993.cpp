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

//bitwise sieve && segmented sieve
const int M = 50000, R = 100000; //limit of seive and max range of segment 
int marked[(M>>6)+9], segment[(R>>6)+9]; //prime flags
vector<int>primes; vector<ll>segment_primes; //primes are stored here
#define ifc(z, n) (z[n>>6]&(1<<((n>>1)&31))) //checks if composite
#define isc(z, n) (z[n>>6]|=(1<<((n>>1)&31))) //marks as composite
void sieve(int n){ //memset "marked" to zero
  for(int i = 3; i*i <= n; i+=2) if(!ifc(marked, i)) 
    for(int j = i * i; j <= n; j += (i + i)) isc(marked, j); 
  primes.pb(2);
  for(int i = 3; i <= n; i+=2) if(!ifc(marked, i)) primes.push_back(i); 
}


void absinthe() {
	sieve(M);
	int n, i = 0; cin >> n;
	for(int i = 0; i < M; i++) {
		if(primes[i]%5==1) {
			n--;	
			cout << primes[i] << " ";
		}
		
		if(n == 0) return;
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
