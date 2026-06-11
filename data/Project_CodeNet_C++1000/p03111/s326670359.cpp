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
	int  n; VI a(3);
	cin >>n >>a[0] >>a[1] >>a[2];
	VI l(n);
	rep(i, n) cin >>l[i];
	ll ans = 1LL<<60;
	int ym=n, xmx=4;  
	vector<int> ct(ym,0);
	auto rcf=[&](auto rcf, int idx){
		if(idx==ym){
			VI sk(4, 0); VL sm(4, 0);
			rep(i, n){ sk[ct[i]]++; sm[ct[i]] +=l[i]; }
			bool ok=true;
			rep(i, 3) if(sk[i]< 1) ok=false;
			if(!ok) return;
			ll zsm = 0;
			rep(i, 3) if(sk[i]>1) zsm += 10 * (sk[i]-1);
			rep(i, 3) zsm += abs(a[i] - sm[i]);
			ans = min(ans, zsm);
			return ;
		}
		rep(i, xmx){
			ct[idx]=i;
			rcf(rcf, idx+1);
		}
	};
	
	rcf(rcf, 0);
	cout << ans <<"\n";
	return 0;
}
