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

const ll N = 1e3+7;
ll n, num = 0, f[2], d[35];
ii a[N];

void solve(ll x, ll y){
	cout<<"\n";
	f(i,1,num){
		if(abs(x) > abs(y)){
			if(x > 0) cout <<"R", x-=d[i];
			else cout <<"L", x+=d[i];
		}else{
			if(y > 0) cout <<"U", y-=d[i];
			else cout <<"D", y+=d[i];
		}
	}
}

signed main(){
//	freopen("PERFECT1.inp","r",stdin);
//	freopen("PERFECT1.out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	f(i,1,n){
		cin >> a[i].x >> a[i].y;
		f[(a[i].x+a[i].y)%2] ++;
	}
	if(f[0]&&f[1]){
		cout <<"-1";
		return 0;
	}
	F(i,30,0) d[++num] = (1<<i);
	if(f[0]) d[++num] = 1;
	cout << num <<"\n";
	f(i,1,num) cout << d[i] <<" ";
	f(i,1,n) solve(a[i].x, a[i].y);
}
