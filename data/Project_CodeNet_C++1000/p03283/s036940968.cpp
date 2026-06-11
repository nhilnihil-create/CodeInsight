#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;
const int mxn=505;
int n,m,q,a[mxn][mxn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	cin >> n >> m >> q;
	for(int i=0; i<m; i++){
		int l,r; cin >> l >> r;
		a[l][r]++;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			a[i][j]+=a[i][j-1];
			
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			a[i][j]+=a[i-1][j];
			
	while(q--){
		int l,r;
		cin >> l >> r;
		cout << a[r][r]+a[l-1][l-1]-a[l-1][r]-a[r][l-1] << endl;
	}
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
