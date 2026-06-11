#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl

using namespace std;

template<typename S,typename T>auto&operator<<(ostream&o,pair<S,T>p){return o<<"{"<<p.fi<<","<<p.se<<"}";}
template<typename T>auto&operator<<(ostream&o,set<T>s){for(auto&e:s)o<<e<<" ";return o;}
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,priority_queue<S,T,U>q){while(!q.empty())o<<q.top()<<" ",q.pop();return o;}
template<typename K,typename T>auto&operator<<(ostream&o,map<K,T>m){for(auto&e:m)o<<e<<" ";return o;}
template<typename T>auto&operator<<(ostream&o,vector<T>v){for(auto&e:v)o<<e<<" ";return o;}
void ashow(){cout<<endl;}template<typename T,typename...A>void ashow(T t,A...a){cout<<t<<" ";ashow(a...);}

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<string> vs;

const int MAX_N = 100005;

int inv[MAX_N],fac[MAX_N],finv[MAX_N];

void make()
{
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(int i=2;i<MAX_N;i++){
		inv[i] = MOD - (ll)inv[MOD%i] * (MOD/i) % MOD;
		fac[i] = (ll)fac[i-1] * i % MOD;
		finv[i] = (ll)finv[i-1] * inv[i] % MOD;
	}
}

int comb(int a,int b)
{
	if(a<b){
		return 0;
	}
	return fac[a] * ((ll)finv[b] * finv[a-b] % MOD) % MOD;
}

inline int add(int x,int y)
{
    return (x+y)%MOD;
}

inline int sub(int x,int y)
{
    return (x+MOD-y)%MOD;
}

inline int mul(int x,int y)
{
    return (ll)x*y%MOD;
}

int a[MAX_N];
int val[MAX_N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    make();
    rep(i,n){
        val[i+1] = add(val[i], inv[i+1]);
    }
    int ans = 0;
    rep(i,n){
        ans = add(ans, mul(a[i], sub(add(val[n-i], val[i+1]),1)));
    }
    cout << mul(ans, fac[n]) << "\n";
    return 0;
}
