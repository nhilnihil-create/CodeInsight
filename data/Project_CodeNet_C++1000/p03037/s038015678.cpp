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
ll n, m, maks=-1, mins=inf;
	
int main(){
	IOS
	cin >> n >> m;
	for(int i=0;i<m;i++){
		ll l, r;
		cin >> l >> r;
		mins=min(mins, r);
		maks=max(maks, l);
	}
	ll temp=mins-maks+1;
	if(temp<0){
		cout << 0 << '\n';
	}
	else{
		cout << temp << '\n';
	}
}
