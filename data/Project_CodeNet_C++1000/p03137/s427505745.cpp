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
ll n, m, arr[nax], ans=0;
vector<ll>v;
	
bool cmp(ll a, ll b){
		return a>b;
	}	
	
int main(){
	IOS
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> arr[i];
	}
	if(n>=m){
		cout << 0 << '\n';
		return 0;
	}
	sort(arr, arr+m);
	for(int i=1;i<m;i++){
		v.pb(arr[i]-arr[i-1]);
		ans+=arr[i]-arr[i-1];
	}
	if(v.empty()){
		cout << 0 << '\n';
		return 0;
	}
	sort(v.rbegin(), v.rend());
	for(int i=0;i<n-1;i++){
		ans-=v[i];
	}
	if(ans<0){
		cout << 0 << '\n';
		return 0;
	}
	cout << ans << '\n';
}
