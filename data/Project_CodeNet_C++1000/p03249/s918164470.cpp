#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,d[200010],dp[200010],sz[200010];
map<int,int> mp;
vector<pair<int,int> > edges,ans;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>d[i];mp[d[i]]=i;edges.push_back(make_pair(d[i],i));}
	sort(edges.begin(),edges.end());
	reverse(edges.begin(),edges.end());
	for(int i=1;i<=n;i++){sz[i]=1;dp[i]=0;}
	for(int i=0;i<edges.size()-1;i++){
		if(sz[edges[i].second]*2>=n){
			cout<<-1<<endl;
			return 0;
		}
		int need=edges[i].first-(n-2*sz[edges[i].second]);
		if(!mp.count(need)){
			cout<<-1<<endl;
			return 0;
		}
		dp[mp[need]]+=dp[edges[i].second]+sz[edges[i].second];
		sz[mp[need]]+=sz[edges[i].second];
		ans.push_back(make_pair(mp[need],edges[i].second));
	}
	if(dp[edges[edges.size()-1].second]!=edges[edges.size()-1].first){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}