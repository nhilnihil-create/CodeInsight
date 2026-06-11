#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Rep(n) for (ll _ = 0; _ < (ll)(n); _++)

template<class S>S sum(vector<S>&a){return accumulate(all(a),S());}
template<class S>S max(vector<S>&a){return *max_element(all(a));}
template<class S>S min(vector<S>&a){return *min_element(all(a));}
ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
ll min(int a,ll b){return min((ll)a,b);} ll min(ll a,int b){return min(a,(ll)b);}
template <class S> void print(vector<S> &v){for(ll i=0; i<(ll)v.size(); i++){cerr << v[i] << ' ';}cerr << endl;}
template <class S> void print(vector<vector<S>> &v) {for (ll i = 0; i < (ll)v.size(); i++) {for (ll j = 0; j < (ll)v[i].size(); j++) {cerr << v[i][j] << ' ';}cerr << endl;}}


int main(){
	int n; cin >> n;
	vector<pair<int,int>> x(n);
	rep(i,n){
		int a; cin >> a;
		x[i] = make_pair(a,i);
	}
	sort(all(x));
	int l = x[n/2-1].first;
	int r = x[n/2].first;
	vector<bool> isleft(n,false);
	rep(i,n){
		if(i < n/2){
			isleft[x[i].second] = true;
		}
	}
	rep(i,n){
		cout << (isleft[i] ? r : l) << endl;
	}
}