#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fo(i,n) for(i=0;i<n;i++)
#define fok(i,k,n) for(i=k;i<n;i++)
#define ci(x) cin>>x;
#define ci2(x,y) cin>>x>>y;
#define co(x) cout<<x<<"\n";
#define co2(x,y) cout<<x<<" "<<y<<"\n";
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;

int main() {
	int n;
	ci(n);
	int i;
	vl h;
	fo(i,n){
		ll temp;
		ci(temp);
		temp-=(i+1);
		h.pb(temp);
	};
	sort(h.begin(),h.end());
	ll sum=0;
	fo(i,n){
		sum+=abs(h[i]-h[n/2]);
	};
	co(sum);
	
	return 0;
}



