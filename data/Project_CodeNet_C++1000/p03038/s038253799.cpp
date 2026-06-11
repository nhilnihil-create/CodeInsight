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
		ll n,m;
		cin >> n >> m;
		map<ll,ll> mpp;
		for(int i=0;i<n;i++){
			ll a;
			cin >>a;
			mpp[a]++;
		}
		
		for(int j=0;j<m;j++){
			ll b,c;
			cin >> b >> c;
			for(auto i:mpp){
				if(i.fi < c){
					if(mpp[i.fi] > b){
						mpp[i.fi] -= b;
						mpp[c] += b;
						break;
					}else{
						b -= mpp[i.fi];
						mpp[c] += mpp[i.fi];
						mpp.erase(i.fi);
					}
				}else break;
			}
			//cout << mpp.size() << "\n";
		}
		ll ans = 0;
		for(auto i:mpp){
			ans += i.fi * i.se;
		}
		cout << ans << "\n";
	}


	return 0;
}
