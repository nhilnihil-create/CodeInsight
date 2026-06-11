#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 1e5+5;
ll n, x, arr[nax];
vector<ll>v;	
	
int main(){
	IOS
	cin >> n >> x;
	arr[0]=x;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	sort(arr, arr+n+1);
	for(int i=1;i<=n;i++){
		v.pb(arr[i]-arr[i-1]);
	}
	if(v.size()==1){
		cout << v[0] << '\n';
		return 0;
	}
	ll fpb=v[0];
	for(int i=1;i<=n;i++){
		fpb=__gcd(fpb, v[i]);
	}
	cout << fpb << '\n';
}
