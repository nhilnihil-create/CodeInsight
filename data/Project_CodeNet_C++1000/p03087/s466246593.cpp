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
ll n, q, pref[nax];
string a;

int main(){
	IOS
	pref[-1]=0;
	cin >> n >> q >> a;
	for(int i=1;i<n;i++){
		if(a[i]=='C'&&a[i-1]=='A'){\
			pref[i]=pref[i-1]+1;
		}
		else{
			pref[i]=pref[i-1];
		}
	}
	while(q--){
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		cout << pref[r]-pref[l] << '\n';
	}
}
