#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MOD 1000000007
#define pi 3.141592653589793238
#define ll long long int
#define P pair<ll, ll>
#define VII vector<P>
#define P_B push_back

ll n;
ll v[101];
ll DP[100001];

int main() {
	
	// ll T; cin>>T; while(T--) 
	{
		
		ll k;
		cin>>n>>k;
		for (ll i = 0; i < n; i++) cin>>v[i];
		memset(DP, 0, sizeof(DP));
		DP[0] = 1;

		for (int i = 0; i < n; i++) {
			vector<int> pref(k+1, 0);

			for (int j = k; j >= 0; j--) {

				int tmp = DP[j];

				int l = j+1, r = j + min(k-j, v[i]);

				if(l <= r) {
					pref[l] = (pref[l] + tmp)%MOD;
					if(r+1 <= k) pref[r+1] = (pref[r+1] - tmp + MOD)%MOD;
				}
			}

			ll sum = 0;

			for (int j = 0; j <= k; j++) {
				sum = (sum +  pref[j])%MOD;
				DP[j] = (DP[j] + sum)%MOD;

			}
		}

		cout<<DP[k];
	}	
	return 0;
}