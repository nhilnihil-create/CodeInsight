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

const long long  int INF = 1e18;
const ld EPS   = 1e-10;
const int MOD  = int(1e9)+7;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template <class BidirectionalIterator>
bool next_partial_permutation(BidirectionalIterator first, BidirectionalIterator middle,BidirectionalIterator last){reverse(middle, last); return next_permutation(first , last);}
#define COUT(x) cout<<x<<"\n"

void Main()
{
	ll N;
	ll result=0;

	cin>>N;
	result=180*(N-2);
	cout << result << "\n";
	return;
}

int main()
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	Main();
}
