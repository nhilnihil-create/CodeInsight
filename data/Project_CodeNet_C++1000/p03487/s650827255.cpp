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
ll n, arr[nax];
unordered_map<ll, ll>cnt;	
unordered_map<ll, bool>vis;
	
int main(){
	IOS
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	sort(arr, arr+n);
	ll ans=0;
	for(int i=0;i<n;i++){
		if(vis[arr[i]]) continue;
		vis[arr[i]]=1;
		if(cnt[arr[i]]==arr[i]) continue;
		else if(cnt[arr[i]]<arr[i]) ans+=cnt[arr[i]];
		else ans+=cnt[arr[i]]-arr[i];
	}
	cout << ans << '\n';
}
