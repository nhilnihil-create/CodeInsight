#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SORTR(x) sort(ALLR(x));
#define SORT(x) sort(ALL(x));
#define SUM(x) accumulate(ALL(A), 0);
#define EACH(i,x) for(typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef vector<char> VC;
typedef vector<VC> VVC;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template <class BidirectionalIterator>
bool next_partial_permutation(BidirectionalIterator first, BidirectionalIterator middle,BidirectionalIterator last){reverse(middle, last); return next_permutation(first , last);}


void Main()
{
	ll R,G,B,N;
	ll result=0;
	cin>>R>>G>>B>>N;
	REP(r,N+1){
		REP(g,N+1){
			ll mod=N-(R*r+G*g);
			if(mod%B==0&&mod>=0)result++;
		}
	}

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
