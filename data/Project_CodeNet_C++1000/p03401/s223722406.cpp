
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

int main(int argc,char ** argv){
	dhoom;
	int n;
	cin >> n;
	int a[n + 2];
	a[0] = a[n+1] = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	ll sum = 0;
	for(int i = 1 ; i <= n + 1 ; i++)
		sum += abs(a[i] - a[i-1]);
	for(int i = 1 ; i <= n ; i++){
		cout << sum + abs(a[i+1] - a[i - 1]) - abs(a[i] - a[i-1]) - abs(a[i+1] - a[i]) << endl;
	}
	return 0;
}
