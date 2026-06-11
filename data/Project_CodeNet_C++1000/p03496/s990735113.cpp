#include <bits/stdc++.h>


#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7; typedef vector<ll> VL;
void dbg(){ cerr << "\n"; }  template <class T, class ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; cin >>n;
	VI a(n);
	rep(i, n) cin >>a[i];
	vector<pii> ans;
	int imx = max_element(all(a)) - a.begin();
	int imn = min_element(all(a)) - a.begin();
	int sw = 1;
	if(abs(a[imx]) >= abs(a[imn])){
		rep(i, n) if(a[i] != a[imx]){
			a[i] += a[imx]; ans.emplace_back(imx+1, i+1);
		}
	}else{
		rep(i, n) if(a[i] != a[imn]){
			a[i] += a[imn]; ans.emplace_back(imn+1, i+1);
		}
		sw=0;
	}
	if(sw){
		rep(i, n-1){
			a[i+1] += a[i]; ans.emplace_back(i+1, i+2);
		}
	}else{
		repr(i, n-1, 1){
			a[i-1] += a[i]; ans.emplace_back(i+1, i);
		}
	}
	//for(auto x :a) cerr<<x<<" "; dbg();	
	cout<< sz(ans)<<"\n";
	for(auto x :ans) cout<<x.first<<" "<<x.second<<"\n";
	return 0;
}
