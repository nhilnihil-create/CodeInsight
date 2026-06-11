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
ld n, k, ans=0;
	
int main(){
	IOS
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		ld d=1.0/n;
		ll now=i;
		while(now<k){
			now*=2;
			d*=0.5;
		}
		ans+=d;
	}
	cout << setprecision(9) << fixed;
	cout << ans << '\n';
}
