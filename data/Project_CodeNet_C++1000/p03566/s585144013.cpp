#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using VI=vector<ll>;
using VD=vector<ld>;
using VVI=vector<VI>;
using VC=vector<char>;
using VVC=vector<VC>;
using VS=vector<string>;
using PLL =pair<ll,ll>;
using PLD=pair<ld,ld>;
using VPLL=vector<PLL>;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element((x).begin(),(x).end())
#define MIN(x) *min_element((x).begin(),(x).end())
#define SORTR(x) sort((x).rbegin(),(x).rend())
#define SORT(x) sort((x).begin(),(x).end())
#define SUM(x) accumulate((x).begin(),(x).end(), 0)
#define FILL(x,a) fill(x.begin(),x.end(),a)
#define EACH(i,x) for(typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define COUT(x) cout<<x<<"\n"

const ll INF = 1e18;
const ld EPS   = 1e-10;
const int MOD  = int(1e9)+7;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template <class BidirectionalIterator>
bool next_partial_permutation(BidirectionalIterator first, BidirectionalIterator middle,BidirectionalIterator last){reverse(middle, last); return next_permutation(first , last);}
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll GCD(VI v){ll a = v[0]; for (ll i = 1; i<SIZE(v); i++) {a = gcd(a, v[i]);} return a;}
ll LCM(VI v){ll a = v[0]; for (ll i = 1; i<SIZE(v); i++) {a = lcm(a, v[i]);} return a;}


void Main()
{
	ll n;
	cin >> n;
	VI t(n+1),v(n+1,0);
	for(ll i=0;i<n;i++) cin >> t[i],t[i]*=2;
	for(ll i=0;i<n;i++) cin >> v[i],v[i]*=2;
	ll to=0;
	ll id=0;
	VI z(8e4+10,0);
	for(ll i=0;i<n;i++) {
		to+=t[i];
		z[id]=min(z[id],v[i]);
		for(id++;id<=to;id++) z[id]=min(z[id-1]+1,v[i]);
		id--;
	}
	ll mv=0;
	double ans=0;
	for(ll i=id-1;i;i--) {
		mv=min(z[i],mv+1);
		ans+=double(mv);
	}
	ans/=4.0;
	cout << ans << "\n";
	return;
}

int main()
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	Main();
}
