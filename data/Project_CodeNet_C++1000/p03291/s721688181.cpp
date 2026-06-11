#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }



int main()
{
	
	cin.tie(0); ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n=sz(s);
	
	vector<VL> dp(n+2, VL(4));
	dp[0][0] = 1;
	rep(i, n){
		rep(j, 4){
			if(s[i]=='?') (dp[i+1][j] += dp[i][j] * 3) %=MD;
			else (dp[i+1][j] += dp[i][j]) %=MD;
		}
		rep(j, 3){
			if(s[i]=='A'+j || s[i]=='?') (dp[i+1][j+1] +=dp[i][j]) %=MD;
		}
	}
	
	cout << dp[n][3] <<"\n";
	return 0;
}
