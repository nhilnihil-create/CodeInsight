#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define FORR(I,A,B) for(ll I = (B-1); I >= (A); --I)
#define SORT(x) (sort(x.begin(),x.end()))
const ll INF=1e18+7;
const ll MOD=1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> a(n);
	FOR(i,0,n)cin>>a[i];
	SORT(a);
	ll x,y=a[0];
	x = a[n-1];
	FOR(i,0,n){
		if(abs(x-2*y)>abs(x-2*a[i]))y=a[i];
	}
	cout << x << " " << y <<endl;
}