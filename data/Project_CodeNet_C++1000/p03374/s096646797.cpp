#include <bits/stdc++.h> 

using namespace std;

#define fcout(d) cout << fixed << setprecision(d)
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define rep1(i,n) for(int (i) = 1; (i) <= (n); ++(i))
#define repU(i,bottom,ceiling) for(int (i) = (bottom); (i) <= (ceiling); ++(i))
#define repD(i,ceiling,bottom) for(int (i) = (ceiling); (i) >= (bottom); --(i))
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define clr(a) memset((a),0,sizeof(a))
#define all(v)  begin((v)),end((v))

typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const vector<pair<int,int>> DIR = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int INF = -1 + (1<<30);
const int MOD = (int)1e9 + 7;

template<typename T> T gcd(T a,T b){ if(a % b){ return gcd(b,a % b); }else{ return b; } }

template<typename T> T lcm(T a,T b){ return a / gcd(a,b) * b; }

long long Pow(long long n,long long m,int mod = MOD){
	long long res = 1,pow = n % mod;
	while(m) {
		if(m & 1) res = (res * pow) % mod;
		pow = (pow * pow) % mod;
		m >>= 1;
	}
	return res;
}

vector<long long> Frac(int range,int mod = MOD){
	vector<long long> frac;
	frac.push_back(1);
	for(int i = 1; i <= range; ++i) frac.push_back((long long)frac.back() * i % mod);
	return frac;
}

long long Comb(int n,int m,int mod = MOD){
	if(n < m || m < 0) return 0;
	vector<long long> frac(Frac(n,mod));
	long long rev = Pow((long long)frac[m] * frac[n-m] % mod,mod-2,mod);
	return rev * frac[n] % mod;
}

template<class T,class U> auto LB(T v,U in){ return lower_bound(v.begin(),v.end(),in); }

template<class T,class U> auto UB(T v,U in){ return upper_bound(v.begin(),v.end(),in); }

unsigned long long next_subset(unsigned long long subset){
	unsigned long long tem = subset + (subset & -subset);
	unsigned long long btm = (~tem & subset) / (subset & -subset) >> 1;
	return btm | tem;
}


int N;
ll C,x[100002],v[100002];

void solve(){
	ll cw_now,acw_now,cw_last = 0,acw_last = 0;
	ll max_cw_1[100002], max_cw_2[100002], max_acw_1[100002], max_acw_2[100002];
	max_cw_1[0] = max_cw_2[0] = max_acw_1[0] = max_acw_2[0] = 0;
	rep1(i,N){
		cw_now = cw_last+x[i-1]-x[i]+v[i];
		acw_now = acw_last-x[N+2-i]+x[N+1-i]+v[N+1-i];
		max_cw_1[i] = max(max_cw_1[i-1],cw_now);
		max_cw_2[i] = max(max_cw_2[i-1],cw_now - x[i]);
		max_acw_1[i] = max(max_acw_1[i-1],acw_now);
		max_acw_2[i] = max(max_acw_2[i-1],acw_now - C + x[N+1-i]);
		cw_last = cw_now;
		acw_last = acw_now;
	}
	ll ans=0;
	rep(i,N+1) ans = max(ans, max_cw_1[i] + max_acw_2[N - i]);
	rep(i,N+1) ans = max(ans, max_cw_2[i] + max_acw_1[N - i]);
	cout<<ans<<endl;
	return;
}

void input(){
	cin>>N>>C;
	x[0]=v[0]=v[N+1]=0;
	x[N+1]=C;
	rep1(i,N) cin>>x[i]>>v[i];
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}



