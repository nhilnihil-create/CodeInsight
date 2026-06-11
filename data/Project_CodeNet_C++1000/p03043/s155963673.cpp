#include<bits/stdc++.h>
#include<string>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define mod (ll)(1e9+7)
#define nax (ll)(1e5)
#define INFL LLONG_MAX
#define NINFL LLONG_MIN
#define INF INT_MAX
#define disp(a,n,arr) for(int i=a;i<(ll)n;i++) cout << arr[i] << " "; cout << "\n";
#define check cout << "Working\n";
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpl vector<pl>
#define vpi vector<pi>
#define vb vector<bool>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(),a.end()
using namespace std;


int main() {
	FIO;
	int t = 1;
	//cin >> t;
	while (t--) {
		ll n,k;
		cin >> n >> k;
		long double ans = 0;
		ll two[26];
		two[0] = 1;
		for(int i=1;i<=25;i++){
			two[i] = two[i-1]*2;
		}
		for(int i=1;i<=n;i++){
			ll l = 0;
			ll r = 25;
			ll cnt = 1;
			ll mid;
			while(l <= r){
				mid = l + (r-l)/2;
				if(two[mid]*i >= k){
					cnt = mid;
					r = mid-1;
				}else l = mid + 1;
			}
			ans += 1 / (double)(two[cnt]*n);
			//cout << cnt << "\n";
		}
		cout << setprecision(12) << fixed << ans << "\n";
	}


	return 0;
}
