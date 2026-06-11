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
	int n,k; cin >> n >> k;
	int nk = k*2 + 1;
	string s; cin >> s;
	vector<int> kukan;
	bool h = (s[0] == '1');
	if(!h){
		kukan.push_back(0);
	}
	int c = 1;
	for(int i=1; i<n; i++){
		if((s[i] == '1') == h) c++;
		else{
			kukan.push_back(c);
			h = !h;
			c = 1;
		}
	}
	kukan.push_back(c);
	if(s[n-1] == '0') kukan.push_back(0);
	int ss = 0;
	int ans = 0;
	rep(i,nk){
		if(i >= (int)(kukan.size())){
			cout << ss << endl;
			return 0;
		}
		ss += kukan[i];
	}
	ans = ss;
	for(int i=0; i<kukan.size()-nk; i+=2){
		ss = ss - kukan[i] + kukan[i+nk] - kukan[i+1] + kukan[i+nk+1];
		ans = max(ss,ans);
	}
	cout << ans << endl;
	//print(kukan);
}