#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define fio	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cout<<fixed<<setprecision(16);
using ll=long long;
using ld=long double;
#define inf INT_MAX 
const ll infll=1LL*inf*inf;
#define mode (ll)998244353
#define mod (ll)1000000007
const long double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define pb push_back
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define f0(i,n) for(ll i=0; i<n; i++)
#define r0(i,n) for(ll i=n-1; i>=0; i--)
#define fab(i,a,b) for (ll i = a; i <= b; i++)
#define fba(i,b,a) for (ll i = b; i >= a; i--)
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define sz(a) ll((a).size())
#define fit(c,i) for(auto i = begin(c); i != end(c); i++)
#define rit(c,i) for(auto i = rbegin(c); i != rend(c); i++)
#define pre(c,x) ((c).find(x) != (c).end())
#define cpre(c,x) (find(all(c),x) != (c).end())
#define mll map<ll,ll>
#define vs vector<string>
#define vi vector<int>
#define vl vector<ll>
#define pl pair<ll,ll>
#define pi pair<int,int>
#define vll vector<pl>
#define vvl vector<vector<ll> >
#define vvi vector< vector<int> >
#define pq priority_queue< ll >
#define pqd priority_queue< ll,vl ,greater< ll > >
#define flush fflush(stdout)
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cerr <<(ll)(it-arr.begin()) << ')' <<  *it << ' '; cerr << endl;
#define print2d(x)  for(auto it1=x.begin();it1!=x.end();it1++) {print((*it1));}
#define printii(x)  for(auto it=x.begin();it!=x.end();it++) cerr<<it->F<<' '<<it->S<<endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#define mems(a,i) memset(a,i,sizeof(a));
#define mid(i,j) ((i+j)>>1)
//#define nl '\n'
#define nl endl
#define lcm(a,b) a/gcd(a,b)*b;
//find_by_order()  // order_of_key()
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> o_s;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
ll rng(ll lim) {
    uniform_int_distribution<ll> uid(0,lim-1);
    return uid(rang);
}
ld max(ld a,ld b) {return (a>b? a:b);}
ld min(ld a,ld b) {return (a>b? b:a);}
ll max(ll a,ll b) {return (a>b? a:b);}
ll min(ll a,ll b) {return (a>b? b:a);}
ll gcd(ll a,ll b) {return (b==0)? a:gcd(b,a%b); }
ll gcd(ll a,ll b,ll & x,ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
ll modinv(ll a,ll b){
	ll x,y;
	gcd(a, b, x, y);
	return (x%b + b)%b;
}
ll bexp(ll a,ll b,ll m){
	a%=m;
	ll res=1;
	while(b>0){
		if(b&1) res=(res*a)%m;
		b>>=1;
		a=a*a%m;
	}
	return res;
}
vvl mat_mul(vvl mat1,vvl mat2,ll mod1){
        vvl res(sz(mat1),vl(sz(mat2[0]),0));
        fab(i,0,sz(mat1)-1){
                fab(j,0,sz(mat2[0])-1){
                        fab(k,0,sz(mat1[0])-1){
                                res[i][j]=(res[i][j]+(mat1[i][k]*mat2[k][j])%mod1)%mod1;
                        }
        }
        }
        return res;
}

vvl mat_exp(vvl mat,ll p,ll mod1){
        vvl res(sz(mat),vl(sz(mat[0]),0));
        fab(i,0,sz(mat)-1) res[i][i]=1;
        while(p>0){
                if(p&1) res=mat_mul(res,mat,mod1);
                mat=mat_mul(mat,mat,mod1);
                p>>=1;
        }
        return res;
}

void sieve(vi &pr,int N){
	int lp[N+1];
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}
//#define DEBUG
const int N=3e2+5;
ll n,m,t,q,p,g,k,x,y,u,v,z,w,l,h,r,ans;
ld dp[N][N][N];
void solve(){
	cin >> n;
	x=y=z=0;
	f0(i,n){
		cin >> p;	
		if(p==1) x++;
		else if(p==2) y++;
		else z++;
	}
	f0(k,301)
	f0(j,301)
	f0(i,301){
		if(i+j+k==0) continue;	
		dp[i][j][k]= ld(n*1.0/(i+j+k));
		if(i>0) dp[i][j][k]+=dp[i-1][j][k]*i/(i+j+k);
		if(j>0) dp[i][j][k]+=dp[i+1][j-1][k]*j/(i+j+k);
		if(k>0) dp[i][j][k]+=dp[i][j+1][k-1]*k/(i+j+k);
	}
	cout << dp[x][y][z] << nl;
}
int main(){
	fio;
	t=1;
	//cin >> t;
	while(t--){
		solve();	
	}
	#ifdef DEBUG 
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
	#endif

}
