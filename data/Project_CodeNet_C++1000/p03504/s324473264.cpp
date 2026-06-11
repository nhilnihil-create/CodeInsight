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
	int n, c;
	cin >>n >>c;
	vector<VI> dt(n, VI(4)), dt2; 
	rep(i, n) cin >>dt[i][1] >>dt[i][2] >>dt[i][0];
	sort(all(dt));
	VI ccr = dt[0];
	rep2(i, 1, n){
		if(ccr[0] == dt[i][0] && ccr[2]==dt[i][1]){
			ccr[2] = dt[i][2];
		}else{
			dt2.push_back(ccr);
			ccr = dt[i];
		}
	}
	dt2.push_back(ccr);
	sort(all(dt2), [](auto& l, auto& r){return l[1] < r[1];});
	VI vdr; int ans = 0;
	for(const auto& x: dt2){
		int add = 1;
		for(auto& z: vdr){
			if( z < x[1]){
				z = x[2]; add = 0; break;
			}
		}
		if(add==1){
			vdr.push_back(x[2]);
			ans = max(ans, sz(vdr));
		}
	}
	cout <<ans <<"\n";
	return 0;
}
