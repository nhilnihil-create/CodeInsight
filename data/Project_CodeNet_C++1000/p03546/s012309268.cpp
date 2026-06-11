// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

ll INF=LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int h,w; cin >> h >> w;
	int cost[10][10],a[h][w];
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cin >> cost[i][j];
		}
	}
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<10; k++){
				cost[j][k] = min(cost[j][k], cost[j][i]+cost[i][k]);
			}
		}
	}
	int ans=0;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin >> a[i][j];
			if(a[i][j]==-1||a[i][j]==1)continue;
			else ans += cost[a[i][j]][1];
		}
	}
	cout << ans << endl;
}	
