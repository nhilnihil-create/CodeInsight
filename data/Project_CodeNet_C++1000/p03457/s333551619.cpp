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
ll n;

struct he{
		ll t, x, y;
	};
he arr[nax];

bool cmp(he s1, he s2){
		return s1.t<s2.t;
	}

int main(){
	IOS
	cin >> n;
	arr[0].t=0, arr[0].x=0, arr[0].y=0;
	for(int i=1;i<=n;i++){
		cin >> arr[i].t >> arr[i].x >> arr[i].y;
	}
	sort(arr, arr+n+1, cmp);
	for(int i=0;i<n;i++){
		ll d=abs(arr[i].x-arr[i+1].x)+abs(arr[i].y-arr[i+1].y);
		ll t=arr[i+1].t-arr[i].t;
		if(d<=t&&d%2==t%2) continue;
		else{
			cout << "No" << '\n'; return 0;
 		}
	}
	cout << "Yes" << '\n';
}
