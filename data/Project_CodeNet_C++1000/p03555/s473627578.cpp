#include<iostream>
#include<bits/stdc++.h>
#include <stdio.h>
#include<unordered_map>
#define Amr_Abdelazim ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll int
#define ld long double
#define pll pair<ll,ll>
#define vll vector<ll>
#define vvll vector<vector<ll> >
#define vpll vector<pair<ll,ll> >
#define P complex<ld>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define rep(i,n)   for(int i=0;i<n;i++)
#define repp(i,s,n)   for(int i=s;i<=n;i++)
#define print(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define mkp make_pair
#define clr(ar,v) memset(ar,v,sizeof(ar));
#define TC ll amr_abdelazim;cin>>amr_abdelazim;while(amr_abdelazim--)
#define popcnt(x) __builtin_popcount(x)
#define EPS 1e-9

using namespace std;
const int mod = 1000000007;

const double pi = acos(-1);
class cmp {
public:
	bool operator() (ll &A, ll &B) {
		return A > B;
	}
};
bool by_sec(const pll &a, const pll &b) {
	if ((abs(a.first) == abs(b.first)))
		return (abs(a.second) < abs(b.second));
	return (abs(a.first) < abs(b.first));
}
bool byth(const tuple<ll, ll, ld>& a, const tuple<ll, ll, ld>& b) {
	return (get<2>(a) < get<2>(b));
}
ld dist(P a, P b) {
	return (ld)abs(a - b);
}

ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
ll max(ll a, ll b) {
	if (a >= b)return a;
	else return b;
}
ll min(ll a, ll b) {
	if (a <= b)return a;
	else return b;
}
const int N = 1005 + 9;
const ll INF = 1000000009;

int main()
{
	Amr_Abdelazim
		string a, b;
	cin >> a >> b;
	reverse(all(b));
	if (a == b)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}