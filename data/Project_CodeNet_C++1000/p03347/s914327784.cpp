/*
ID: mm.khan1
PROG: beads
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

//#pragma GCC target ("sse4.2")
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FILE_IO ifstream cin ("beads.in"); ofstream cout ("beads.out");
#define pii pair<int, int>
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const int MAX_I = 1e5*3;
const int N = 1e6;
const ll mud = 1e9 + 7;
ll a[N];

int main(){
	FAST_IO;
	//FILE_IO;	
	
	ll n;
	cin >> n;
	for (ll i=0;i<n;i++) cin>>a[i];

	bool ans=1;
	for (ll i=n-2;i>=0;i--){
		if (a[i]<max(0LL, a[i+1]-1) || a[i]>i){
			ans=0;
			break;
		}
	}
	if (!ans || a[0]){
		cout << "-1\n";
		return 0;
	}

	ll cnt=0, cur=0;
	for (ll i=n-1;i>=0;i--){
		if (cur<a[i]){
			cur=a[i];
			cnt+=a[i];
		}
		cur = max(0LL, cur-1);
	}

	cout << cnt << '\n';

	return 0;
}
