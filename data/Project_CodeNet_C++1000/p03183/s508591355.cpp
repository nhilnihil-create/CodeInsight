#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int llint;
llint dp[1005][10005],n;
vector <pair<pair<int,llint>,llint> > v;
bool f(pair <pair<int,llint>,llint> p1,pair <pair<int,llint>,llint> p2) {
	return p1.first.second-p2.first.first>p2.first.second-p1.first.first;
}
llint rek(int x,llint y) {
	if(x==n) return 0;
	if(dp[x][y]!=-1) return dp[x][y];
	llint ret=0;
	ret=max(ret,rek(x+1,y));
	if(y>=v[x].first.first) ret=max(ret,rek(x+1,min(v[x].first.second,y-v[x].first.first+llint(1e5*(y==1e4+1))))+v[x].second);
	dp[x][y]=ret;
	//cout << x << " " << y << " " << ret << "\n";
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0;i<n;i++) {
		llint w,s,v1;
		cin >> w >> s >> v1;
		v.push_back(make_pair(make_pair(w,s),v1));
	}
	sort(v.begin(),v.end(),f);
	/*for(int i=0;i<n;i++) {
		cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second << "\n";
	}
	cout << "\n";*/
	memset(dp,-1,sizeof(dp));
	cout << rek(0,1e4+1);
	return 0;
}
