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

const VI prm ={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; cin >>n;
	VI v(105), dp(78);
	for(auto p: prm){
		for(ll w = n; w>0; w/=p) v[p] += w/p;
	}
	dp[1] = 1;
	rep(i, 76){
		VI np(78);
		rep(j, 76) rep(k, v[i]+1) if(j *(k+1) <=75) np[j *(k+1)] += dp[j];
		swap(np, dp);
	}
	cout << dp[75] <<"\n";
	return 0;
}
