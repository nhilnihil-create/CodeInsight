#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend() 
#define pb push_back
#define fastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int n,a,b;

int main () {
	fastIO();
	cin >> n >> a >> b;
	if((a-b-1) % 2)
		cout << "Alice\n";
	else
		cout << "Borys\n";
	return 0;
}
