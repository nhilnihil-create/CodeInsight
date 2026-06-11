#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> P;
typedef pair<ll, pair<int, int> > PP;
const int MAX=1e5+10;
const ll MOD=1e9+7;

ll extgcd(ll a,ll b,ll& x, ll& y){
	ll d=a;
	if(b!=0){
		d = extgcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
	else{
		x = 1; y = 0;
	}
	return d;
}
ll mod_inv(ll a,ll m){
	ll x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

int main(){
	int N;
	cin >> N;
	ll A[MAX];
	rep1(i,N) cin>>A[i];
	ll ism[MAX];
	ism[0] = 0;
	rep1(i,N){
		ism[i] = ism[i-1] + mod_inv(i , MOD);
	}
	ll ans = 0;
	rep1(i,N){
		ll tmp = (ism[i] + ism[N+1-i] - 1 + MOD) % MOD;
		tmp = (tmp * A[i]) % MOD;
		ans = (ans + tmp) % MOD;
	}
  	rep1(i,N) ans = (ans * i) % MOD;
	cout << ans << endl;
}
