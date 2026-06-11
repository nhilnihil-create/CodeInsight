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

bool comp(pair<string,pl> p1,pair<string,pl> p2){
	if(p1.fi < p2.fi) return true;
	if(p1.fi == p2.fi && p1.se.fi > p2.se.fi) return true;
	return false;
}

int main() {
	FIO;
	int t = 1;
	//cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<pair<string,pl> > v(n);
		for(int i=0;i<n;i++){
			cin >> v[i].fi >> v[i].se.fi;
			v[i].se.se = i+1;
		}
		sort(all(v),comp);
		for(int i=0;i<n;i++){
			cout << v[i].se.se << "\n";
		}
	}


	return 0;
}
