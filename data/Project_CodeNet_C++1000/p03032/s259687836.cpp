#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(n) for (ll _ = 0; _ < (ll)(n); _++)
#define P pair<ll,ll>
#define fs first
#define sc second

template<class S>S sum(vector<S>&a){return accumulate(all(a),S());}
template<class S>S max(vector<S>&a){return *max_element(all(a));}
template<class S>S min(vector<S>&a){return *min_element(all(a));}
ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
ll min(int a,ll b){return min((ll)a,b);} ll min(ll a,int b){return min(a,(ll)b);}
template <class S> void print(vector<S> &v){for(ll i=0; i<(ll)v.size(); i++){cerr << v[i] << ' ';}cerr << endl;}
template <class S> void print(vector<vector<S>> &v) {for (ll i = 0; i < (ll)v.size(); i++) {for (ll j = 0; j < (ll)v[i].size(); j++) {cerr << v[i][j] << ' ';}cerr << endl;}}

int main(){
	int n,k; cin >> n >> k;
	vector<ll> v(n);
	rep(i,n) cin >> v[i];
	int m = min(n,k);
	ll ans = 0;
	rep(a,m+1){
		rep(b,m+1){
			if(a+b > n || a+b > k) continue;
			ll res = 0;
			priority_queue<ll> q;
			rep(i,a){
				ll tmp = v[i];
				res += tmp;
				if(tmp < 0)
					q.push(-tmp);
			}
			rep(i,b){
				ll tmp = v[n-i-1];
				res += tmp;
				if(tmp < 0)
					q.push(-tmp);
			}
			Rep(k-a-b){
				if(q.empty()) break;
				res += q.top();
				q.pop();
			}
			ans = max(ans, res);
		}
	}
	cout << ans << endl;
}