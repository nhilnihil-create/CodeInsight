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
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 1010;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code
int main()
{
	ll n;
	cin>>n;
	vector<int> v(n);
	rep(i,0,n) cin>>v[i];
	ll r = 0;
	ll x = 0;
	ll ans = 0;
	for(ll l = 0; l<n; l++)
	{
		while(r < n && ((x^v[r]) == (x+v[r])))
		{
			x = x ^v[r];
			r++;
		}
		ans += (r - l);
		// cout<<l<<" "<<r<<endl;
		x ^= v[l];
	}
	cout<<ans<<endl;
}
