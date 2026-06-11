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
const ll nax = 1e5+5;
ll n, arr[nax], pref[nax], sums=0;

int main(){
	IOS
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> arr[i];
	}
	pref[0]=0, pref[n+1]=0;
	for(int i=1;i<=n+1;++i){
		pref[i]=abs(arr[i]-arr[i-1]);
		sums+=pref[i];
	}
	for(int i=1;i<=n;++i){
		cout << sums-abs(arr[i]-arr[i-1])-abs(arr[i]-arr[i+1])+abs(arr[i-1]-arr[i+1]) << '\n';
	}
}
