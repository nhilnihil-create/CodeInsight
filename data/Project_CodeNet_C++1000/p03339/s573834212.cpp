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
const ll nax = 3e5+5;
ll n, pref[nax];
string s;
	
int main(){
	IOS
	cin >> n >> s;
	if(s[0]=='W') pref[0]=1;
	else pref[0]=0;
	for(int i=1;i<n;i++){
		pref[i]=pref[i-1];
		if(s[i]=='W'){
			pref[i]++;
		}
	}
	ll mins=inf;
	mins=min(mins, (n-1)-(pref[n-1]-pref[0]));
	for(int i=1;i<n;i++){
		ll ans=pref[i-1];
		ans+=(n-1)-i-(pref[n-1]-pref[i]);
		mins=min(mins, ans);
	}
	cout << mins << '\n';
}
