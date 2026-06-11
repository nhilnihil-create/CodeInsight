#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long int
#define P pair<ll, ll>
#define vii vector<P>
#define vvi vector<vector<ll>>
#define P_B push_back

#define MOD 1000000007
#define pi 3.141592653589793238


int main() {
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	// ll T; cin>>T; while(T--) 
	{
		
		ll n;
		cin>>n;

		vector<ll> v(n);
		for (int i = 0; i < n; i++) cin>>v[i];

		ll DP[n][n];

		for (ll l = n-1; l >= 0; l--) {

			for (int r = l; r < n; r++) {
				
				if(r == l) {
					DP[l][r] = 0;
					continue;
				}

				ll sum = 0;
				for (int i = l; i <= r; i++) sum += v[i];
				DP[l][r] = 1e18L;

				for (int p = l; p < r; p++) {
					DP[l][r] = min( DP[l][r] , DP[l][p] + DP[p+1][r] + sum);
				}
			}
			
		}

		cout<<DP[0][n-1];

	}	
	return 0;
}   