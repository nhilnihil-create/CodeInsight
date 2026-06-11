#include <bits/stdc++.h>
#include <vector>

using namespace std;
 
#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

typedef int64_t ll; typedef vector<int> VI; typedef pair<int,int> pii;
const ll mod = 1e9+7;

void dbg(){ cerr << "\n"; }  
template <typename T,typename ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }

const int KS=8100;
array<bool, 2*KS+100> dp, np;

bool fnc(const VI& xs, int tx, bool xyx=false){
	dp.fill(false); dp[KS] = true;
	rep(i, sz(xs)){
		np.fill(false);
		if(xs[i]==0) continue;
		rep(j, KS*2) if(dp[j]){
			if(j + xs[i] < KS*2) np[j + xs[i]] = true;
			if(xyx && i==0) continue;
			if(j - xs[i] >= 0  )   np[j - xs[i]] = true;
		}
		swap(np, dp);
	}
	return dp[tx + KS];
}



int main()
{
 
	cin.tie(0); ios_base::sync_with_stdio(false);
	int x,y;
	string s;
	cin >> s >>x >>y;
	s +="T";
	int n=sz(s), cr=0;
	VI xs, ys;
	int sm =0;
	rep(i, n){
		if(s[i]=='F') sm++;
		else if(s[i]=='T'){
			(cr? ys:xs).push_back(sm);
			sm =0; cr ^=1;
		}
	}
	if(fnc(xs, x, true) && fnc(ys, y)) puts("Yes");
	else puts("No");
	return 0;
}
