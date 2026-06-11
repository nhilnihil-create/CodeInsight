#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
const ll LINF = 1e18 + 5;

int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	int m, k;
 	cin >> m >> k;
 	int up = (1<<m)-1;
 	if(k>up) cout << -1;
 	else if(m==1 && k==1) cout << -1;
 	else if(m==1 && k==0) cout << "0 0 1 1";
 	else
 	{
 		vector <int> a;
 		for(int i=0; i<=up; i++)
 		{
 			if(i==k) continue;
 			a.pb(i);
 		}
 		a.pb(k);
 		for(int i=up; i>=0; i--)
 		{
 			if(i==k) continue;
 			a.pb(i);
 		}
 		a.pb(k);
 		for(auto x : a) cout << x << ' ';
 	}
	return 0;
}
