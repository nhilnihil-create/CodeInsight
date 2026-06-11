#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long int ll;
#define int long long int
typedef vector<ll> vi;
typedef pair<int, int> ii; typedef vector<ii> vii;
#define INF numeric_limits<ll>::max()
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
ll powmod(ll a,ll l, ll md){ll res=1;while(l){if(l&1)res=res*a%md;l/=2;a=a*a%md;}return res;}
ll binpow(ll a,ll l){ll res=1;while(l){if(l&1)res=res*a;l/=2;a=a*a;}return res;}
ll invmod(ll a, ll md){return powmod(a,md-2,md);}
const ll inf = 0xFFFFFFFFFFFFFFFL;


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	cin>>s;
	ll n = s.length();
	ll cnt =0, ind = 0, ind_l = 0, cnt_temp = 0; 
	while(ind<=n-2){
		if (s[ind]=='A'){
			ind+=1;
			cnt_temp+=1;
		}
		else if (ind<=n-2 && s[ind]=='B' && s[ind+1]=='C' ){
			cnt+=cnt_temp;
			ind+=2;
		}
		else{
			cnt_temp = 0;
			ind+=1;
		}


	}
	cout<<cnt<<"\n";
    return 0;
}
