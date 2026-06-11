#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The Value Of " << #val << " is : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
ll n, y;

int main(){
	IOS
	cin >> n >> y;
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=n;j++){
			ll k=n-i-j;
			if(k<0) continue;
			if(10000*i+5000*j+1000*k==y){
				cout << i << ' ' << j << ' ' << k << '\n';
				return 0;
			}
		}
	}
	cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
}
