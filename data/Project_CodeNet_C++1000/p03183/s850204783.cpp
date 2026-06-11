#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct info{
	ll w,s,v;
	info(ll _w,ll _s,ll _v){
		w = _w;
		s = _s;
		v = _v;
	}
	bool operator<(const info &b)const{
		return w+s < b.w+b.s;
	}
};
const int maxn = 1000+10;
const int maxsumW = 10000+10;
ll memo[maxn][maxsumW];
vector<info> A;
int N;

ll dp(int pos,int sumw){
	if(pos >= N)return 0;
	ll &res = memo[pos][sumw];
	if(res != -1)return res;
	res = dp(pos+1,sumw);
	if(sumw <= A[pos].s){
		res = max(res,A[pos].v+dp(pos+1,min(sumw+A[pos].w,10000ll+5)));
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	forn(i,0,maxn)forn(j,0,maxsumW)memo[i][j] = -1;
	cin >> N;
	forn(i,0,N){
		ll w,s,v; cin >> w >> s >> v;
		A.pb(info(w,s,v));
	}
	sort(all(A));
	cout << dp(0,0) << '\n';
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/
