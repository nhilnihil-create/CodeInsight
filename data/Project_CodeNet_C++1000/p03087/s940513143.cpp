#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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
	int n,q; cin >> n >> q;
	string s; cin >> s;
	vector<int> ac(n,0);
	int state = 0;
	rep(i,n){
		if(i) ac[i] = ac[i-1];
		if(state == 0){
			if(s[i] == 'A'){
				state++;
			}
		}else if(state == 1){
			if(s[i] == 'C'){
				ac[i]++;
			}else if(s[i] == 'A'){
				state++;
			}
			state--;
		}
	}
	Rep(q){
		int l,r; cin >> l >> r;
		--l; --r;
		if(l==0){
			cout << ac[r] << endl;
		}else{
			cout << ac[r] - ac[l-1] - (s[l-1] == 'A' && s[l] == 'C') << endl;
		}
	}
}
