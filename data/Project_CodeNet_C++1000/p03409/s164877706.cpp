#include<bits/stdc++.h>
#include<bitset>


using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=st; i--)

typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 1010;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code

vector<tuple<int, int, char>> v;
int main()
{
	int n;
	cin>>n;
	rep(i, 0, n)
	{
		int x, y;
		cin>>x>>y;
		v.pb(make_tuple(x, y, 'R'));
	}
	rep(i, 0, n)
	{
		int x,y;
		cin>>x>>y;
		v.pb(make_tuple(x, y, 'B'));
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int r = 0;
	set<int> s;
	for(auto x: v)
	{
		if(get<2>(x) == 'R')
		{
			s.insert(get<1>(x));
			r++;
		}
		else if(r > 0)
		{
			int y = get<1>(x);
			auto itr = s.lower_bound(y);
			if(itr == s.begin()) continue;
			itr--;
			ans++;
			r--;
			s.erase(itr);
		}
	}
	cout<<ans<<endl;
}
