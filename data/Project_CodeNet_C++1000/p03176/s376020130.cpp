#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define mt make_tuple
#define MOD 1000000007
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector <long long int>
#define pii pair <int,int>
#define pll pair <long long int, long long int>
#define vpii vector< pair<int,int> >
#define vpll vector < pair <long long int,long long int> >
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
const int inf = 1e9 + 5;
const ll inf64 = 1e18 + 5;

const int MAX = 2e5 + 5;
ll BIT[MAX];
// 1-index queries
void upd(int i, ll val)
{
	for(; i < MAX; i += i&-i)
	BIT[i] = max(BIT[i], val);
}
ll qry(int i)
{
	ll sum = 0;
	for(; i; i -= i&-i)
	sum = max(sum, BIT[i]);
	return sum;
}
int main()
{
	boost;
	int n, i;
	cin >> n;
	int h[n], a[n];
	fo(i, 0, n)
	cin >> h[i];
	fo(i, 0, n)
	cin >> a[i];
	
	ll dp[n];
	fo(i, 0, n) {
		dp[i] = a[i] + qry(h[i] - 1);
		upd(h[i], dp[i]);
	}
	cout << *max_element(dp, dp + n);	
}
