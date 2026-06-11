#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define reverse(x) reverse(x.begin(), x.end())
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long,long long>
#define f first
#define s second
typedef long long ll;
const int mod = 1e9+7;
const int N = 1005;
using namespace std;
ll x, y, z ,K;
ll a[N], b[N], c[N], n;

int main(){
	ll i, j, k;
	cin >> x >> y >> z;
	cin >> K;
	for(i=0;i<x;i++)cin >> a[i];
	for(i=0;i<y;i++)cin >> b[i];
	for(i=0;i<z;i++)cin >> c[i];

	sort(a,a+x, greater<ll>());
	sort(b,b+y, greater<ll>());
	sort(c,c+z, greater<ll>());

	vector<ll> vec;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			for(k=0;k<z;k++){
				if((i+1)*(j+1)*(k+1) <= K)vec.pb(a[i]+b[j]+c[k]);
				else break;
			}
		}
	}
	sort(all(vec), greater<ll>());
	for(i=0;i<K;i++){
		printf("%lld\n",vec[i]);
	}
	return 0;
}
