#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;
const int INF=1e9;
const int Max_T=1e5+10;
const int Max_C=35;

bool now[Max_T][Max_C];

int main(){
	int N, C;
	cin >> N >> C;
	vector<vector<P>> channel(C);
	rep(i,N){
		int s, t, c;
		cin >> s >> t >> c;
		s--; t--; c--;
		channel[c].emplace_back(P(t,s));
	}
	rep(i,C) sort(channel[i].begin(),channel[i].end());
	rep(time,Max_T){
		rep(i,C){
			P p={time,-1};
			auto itr=upper_bound(channel[i].begin(),channel[i].end(),p);
			if(itr!=channel[i].end() && itr->second<=time) now[time][i]=true;
		}
	}
	int ans=0;
	rep(i,Max_T){
		int res=0;
		rep(j,C) if(now[i][j]) res++;
		ans=max(ans,res);
	}
	cout << ans << endl;

	return 0;
}