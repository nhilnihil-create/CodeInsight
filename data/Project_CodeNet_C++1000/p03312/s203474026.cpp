#include <bits/stdc++.h>
#define ll long long
#define f(i, a, b) for(ll i = a; i <= b; ++i)
#define ff(i, a, b) for(ll i = a; i < b; ++i)
#define F(i, a, b) for(ll i = a; i >= b; --i)
#define FF(i, a, b) for(ll i = a; i > b; --i)
#define x first
#define y second
#define X real()
#define Y imag()
using namespace std;
typedef complex<ll> P;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;

const ll N = 2e5+7;
const ll INF = 1e9+7;
ll n, ahihi, ahuhu, ans, pos1, pos2, f[N], a[N];
vector<ll> arr;
ll cnp(ll l, ll r){
	ll tb = (f[r]-f[l-1])/2;
	ll k = l-1;
	for(ll i = n/2; i >= 1; i/=2){
		while(k + i < r && f[k+i] - f[l-1] < tb) k+=i;
	}
	return k;
}
ll add[] = {1, 0};
signed main(){
	scanf("%lld", &n);
	f[0] = 0;
	f(i,1,n){
		scanf("%lld", &a[i]);
		f[i] = f[i-1] + a[i];
	}
	ans = INF;
	f(i,2,n-2){
		ahihi = cnp(1, i);
		ahuhu = cnp(i+1, n);
		ff(j,0,2){
			ff(k,0,2){
				pos1 = ahihi + add[j];
				pos2 = ahuhu + add[k];
				if(pos1 == i || pos2 == n) continue;
				arr.push_back(f[pos1]-f[0]);
				arr.push_back(f[i]-f[pos1]);
				arr.push_back(f[pos2]-f[i]);
				arr.push_back(f[n]-f[pos2]);
				sort(arr.begin(), arr.end());
				ans = min(ans, arr.back() - arr[0]);
				arr.clear();
			}
		}
	}
	printf("%lld", ans);
}