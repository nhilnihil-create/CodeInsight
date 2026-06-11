
#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
const ll inf = 1e18;
const int nax = 2e6 + 7;
const ll mod = (1LL<<40);
using namespace std;
ll exp(ll a , ll b){
	if(b == 0)	return 1;
	int x = b % 2 == 0 ?   ((exp(a , b/2)%mod)*(exp(a , b / 2)%mod))%mod :  (a%mod*exp(a , b - 1) % mod)%mod;
	return x;
}
set< int > a[100005];
vector< int > col(100005);
int has[100005];
int main(int argc,char ** argv){
	dhoom;
	ll n , m;
	cin >> n >> m;
	if(n > m)
		swap(n , m);
	if(n == 1 && m == 1)	
		return cout << 1 ,0;
	else if(n == 1)
		return cout << m - 2 , 0;
	else 
		cout << (m - 2LL)*(n - 2LL) << endl;
	return 0;
}
