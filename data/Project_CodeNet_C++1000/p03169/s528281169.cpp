#include<iostream>
#include<bits/stdc++.h>
#include <stdio.h>
#include<unordered_map>
#define Amr_Abdelazim ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define vll vector<ll>
#define vvll vector<vector<ll> >
#define vpll vector<pair<ll,ll> >
#define P complex<ld>
#define X real()
#define Y imag()
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
#define INF 1000000000000000009
#define heeer cout<<"heeeeeeeeer\n";
using namespace std;
//freopen("output.txt", "w", stdout);
//freopen("input.txt", "r", stdin);
const int mod = 1000000007;
const double pi = acos(-1);
class cmp{
public:
	bool operator() (ll &A, ll &B){
		return A > B;
	}
};
bool by_sec(const pll &a, const pll &b){
	if ((abs(a.first) == abs(b.first)))
		return (abs(a.second) < abs(b.second));
	return (abs(a.first) < abs(b.first));
}
bool byth(const tuple<ll, ll, ld>& a, const tuple<ll, ll, ld>& b){
	return (get<2>(a) < get<2>(b));
}
ld dist(P a, P b){
	return (ld)abs(a - b);
}
ll fact[1000009], inv[1000009];
ll fp(ll a, ll b){
	if (b == 0)
		return 1;
	ll ans = fp(a, b / 2);
	ans = (ans * ans)%mod;
	if (b % 2 != 0)
		ans = (ans * (a%mod))%mod;
	return ans;
}
void FacInv(ll n){
	fact[0] = inv[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		fact[i] = ((i%mod) * fact[i - 1] % mod) % mod;
		inv[i] = fp(fact[i], mod - 2);
	}
}
ll ncr(ll n, ll r){
	return (((fact[n] * inv[r]) % mod) * inv[n - r]) % mod;
}
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a%b);
}
ll max(ll a, ll b){
	if (a >= b)return a;
	else return b;
}
ll min(ll a, ll b){
	if (a <= b)return a;
	else return b;
}
const int N = 2 * 1000000 + 9;
ll n;
ld dp[300 + 9][300 + 9][300 + 9];
ld fun(ll a,ll b,ll c){
	//cout << a << " " << b << " " << c << "\n";
	if (a == 0 && b == 0 && c == 0)return 0;
	ld &ans = dp[a][b][c];
	ld x =  (ld)n/(a + b + c);
	if (ans == -1){
		ans = 0;
		if (a > 0){
			ans += fun(a - 1, b, c)*((ld)a / (ld)(a + b + c)) + (x*((ld)a / (ld)(a + b + c)));
		}
		if (b > 0){
			ans += fun(a + 1, b - 1, c)*((ld)b / (ld)(a + b + c)) + (x*((ld)b / (ld)(a + b + c)));
		}
		if (c > 0){
			ans += fun(a, b + 1, c - 1)*((ld)c / (ld)(a + b + c)) + (x*((ld)c / (ld)(a + b + c)));
		}
	}
	return ans;
}
ll c[5];
int main()
{
	Amr_Abdelazim
		rep(i, 300 + 8)rep(j, 300 + 8)rep(k, 300 + 8)dp[i][j][k] = -1;
	cin >> n;
	vll v(n);
	rep(i, n)cin >> v[i],c[v[i]]++;
	cout << fixed << setprecision(9) << fun(c[1],c[2],c[3]) << "\n";
		
	
	return 0;
}
