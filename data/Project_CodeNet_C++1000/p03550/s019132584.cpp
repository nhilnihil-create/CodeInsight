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
typedef pair<ll, ll> pll;

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, z, w;
	cin >>n >>z >>w;
	VI a(n);
	rep(i, n) cin >>a[i];
	
	vector<VI> mem(n+2, VI(2, -1)); 
	
	auto f=[&](auto f, int xs, int ys, int si, int gk)->int{
		if(mem[si][gk] != -1) return mem[si][gk];
		if(si == n) return abs(xs - ys);
		int rtn =0;
		if(gk ==0){
			rtn = 0;
			rep2(i, si, n){
				rtn = max(rtn, f(f, a[i], ys, i+1, 1));
			}
		}else{
			rtn = MD;
			rep2(i, si, n){
				rtn = min(rtn, f(f, xs, a[i], i+1, 0));
			}
		}
		return mem[si][gk] = rtn;
	};

	cout <<f(f,z,w,0,0) <<"\n";
	return 0;
}
