#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<ll,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >>n;
	VI x(n),y(n), h(n);
	rep(i, n) cin >>x[i] >>y[i] >>h[i];
	int MX=101;
	rep(i,  MX) rep(j, MX) {
		bool ok = true; int hi = -1;
		rep(z, n) if(hi==-1 && h[z] > 0){
			hi = h[z] + abs(x[z]-i) + abs(y[z]-j);
			break;
		}
		rep(z, n){
			if( max(hi - abs(x[z]-i) - abs(y[z]-j), 0) != h[z]){
				ok=false; break;
			}
		}
		if(ok){
			cout << i <<" "<<j <<" "<<hi <<"\n";
			return 0;
		}
	}
	return 0;
}
