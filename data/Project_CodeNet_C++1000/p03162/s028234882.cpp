#include <bits/stdc++.h>
#include<string>
using namespace std;


typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string>vst;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
#define all(ct) ct.begin() , ct.end()
#define endl "\n"
#define fr(i,a) for(auto i:a)
#define f(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define in(d,v) d.find(v)!=d.end()
#define mp make_pair
#define size1(a) int(a.size())
#define FOR(n) for(int i= 0;i<n;i++)
#define FORR(n) for(ll i= 0;i<n;i++)



// adjacency list graph input

// vector<vector<int> > adj(n, vector<int>());
// for (size_t i = 0; i < m; i++) {
// 	int x, y;
// 	cin >> x >> y;
// 	adj[x - 1].push_back(y - 1);

//}

int main() {
	fastio;



	int  n ;
	cin >> n ;
//	vi h(3, 0 );
	vi dp(3, 0);
	for (int i = 0; i < n ; i++) {
		vi dp_new(3,  0 );
		vi h;
		for (int  j = 0 ; j < 3 ; j++) {
			int x ;
			cin >> x;
			h.pb(x);
		}
		//cout << int(h.size());
		//for (auto x : h) {cout << x << " ";}

		for (int j = 0 ; j < 3 ; j++) {
			for (int k = 0 ; k < 3 ; k++) {
				if (k != j) {
					dp_new[j] = max(dp_new[j], h[j] + dp[k]);
				}
			}
		}
		dp = dp_new;
	}
	cout << max({dp[0], dp[1], dp[2]});
	return 0;


}
