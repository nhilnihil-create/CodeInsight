#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}



int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, k;
	string s;
	cin >>n >>k >>s;
	s += "Z";
	VI rz;
	int sm = 1;
	rep2(i, 1, n+1){
		if(s[i-1] != s[i]){
			rz.push_back(sm); sm=1;
		}else sm++;
	}
	int m=sz(rz);
	VL as(m+1);
	rep(i, m) as[i+1] = as[i] + rz[i];
	
	ll ans = 0; int gk = s[0]=='1'? 0: 1;
	rep(i, m){
		if(i%2==gk) ans = max<ll>(ans, as[min(m,i+k*2+1)] - as[i]);
		else ans = max<ll>(ans, as[min(m,i+k*2)] - as[i]);
	}
	cout << ans <<"\n";
	return 0;
}
