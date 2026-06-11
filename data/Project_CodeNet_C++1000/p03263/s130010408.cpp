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

ll gcd(ll x, ll y){ return y? gcd(y, x%y): x; }

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int h, w;;
	cin >>h >>w;
	vector<VI> a(h, VI(w));
	rep(i, h) rep(j, w) cin >>a[i][j];
	int cry =0, py=-1, px=-1;
	vector<VI> ans;
	rep(i, h) rep(j, w){
		int nj = i%2? w-1-j: j;
		if(!cry && a[i][nj] %2==0) continue;
		if(!cry && a[i][nj] %2){
			cry =1; py=i; px=nj;
		}else if(cry){
			ans.push_back({py+1,px+1,i+1,nj+1});
			if(a[i][nj] %2) cry = 0;
			else{cry =1; py=i; px=nj;}
		}
	}
	printf("%d\n", sz(ans));
	for(auto x:ans){
		printf("%d %d %d %d\n",x[0],x[1],x[2],x[3]);
	}
	return 0;
}
