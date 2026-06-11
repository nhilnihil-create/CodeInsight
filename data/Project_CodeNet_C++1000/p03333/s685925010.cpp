#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P std::pair<int,int>
#define PiP std::pair<int,std::pair<int,int>>
#define all(v) v.begin(),v.end()
#define mkp std::make_pair
#define prique(T) std::priority_queue<T,vector<T>,greater<T>>
using namespace std;
template<class T> inline void chmax(T& a, T b) { a = std::max(a, b); }
template<class T> inline void chmin(T& a, T b) { a = std::min(a, b); }
 
bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return x != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}
int get_rand(int MIN, int MAX) {
	std::random_device rnd;
	std::mt19937 mt32(rnd());
	std::uniform_int_distribution<int>engine(MIN, MAX);
	return engine(mt32);
}
/*--------Library Zone!--------*/

int n,l[114514],r[114514];
signed main(){
	cin>>n;
	rep(i,n){
		cin>>l[i]>>r[i];
		l[i]*=2;r[i]*=-2;
	}
	sort(l,l+n,greater<>());sort(r,r+n,greater<>());
	rep(i,n){
		l[i+1]+=l[i];r[i+1]+=r[i];
	}
	int ans=0;
	rep(i,n){
		int ans1,ans2,ans3;
		if(!i)ans1=l[i];
		else ans1=l[i]+r[i-1];
		ans2=l[i]+r[i];
		ans3=l[i]+r[i+1];
		chmax(ans,max({ans1,ans2,ans3}));
	}
	cout<<ans<<endl;
}
