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
ll n, k, arr[nax];
	
int main(){
	IOS
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}	
	sort(arr, arr+n);
	ll mins=inf;
	for(int i=0;i+k<=n;i++){
		mins=min(mins, arr[i+k-1]-arr[i]);
	} 
	cout << mins << '\n';
}
