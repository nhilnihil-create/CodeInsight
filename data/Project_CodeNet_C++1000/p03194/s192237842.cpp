#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (int i = 0; i < n; i++)
#define IREP(i, n) for (int i = n - 1; i >= 0; i--)
#define REPEACH(i,k) for(auto& i:k)
#define all(a) a.begin(),a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;
ll prime(double a,double n){
	ll tmp=a;
	ll tmp1=n;
	for(ll i=static_cast<ll>(pow(a,(1.0/n)))+1;i>0;i--){
		if(tmp%(static_cast<ll>(pow(i,n)))==0){
			return i;
		}
	}
}
signed main() {
	double n,p;
	cin >> n >> p;
	ll ans=prime(p,n);
	cout << ans << endl;
}