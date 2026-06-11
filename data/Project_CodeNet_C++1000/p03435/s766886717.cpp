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
	int c[3][3];
	rep(i,3){
		rep(j,3){
			cin >> c[i][j];
		}
	}
	int c10 = c[0][1] - c[0][0];
	int c20 = c[0][2] - c[0][0];
	int r10 = c[1][0] - c[0][0];
	int r20 = c[2][0] - c[0][0];
	for(int i=1; i<3; i++){
		if(c[i][1] - c[i][0] != c10 || c[i][2] - c[i][0] != c20 || c[1][i] - c[0][i] != r10 || c[2][i] - c[0][i] != r20){
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";

}