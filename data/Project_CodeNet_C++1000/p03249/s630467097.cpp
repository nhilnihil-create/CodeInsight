//Written by Zhu Zeqi
//Come on,baby
//Hack,please
#include <iostream> 
#include <cstdio> 
#include <fstream> 
#include <algorithm> 
#include <cmath> 
#include <deque> 
#include <vector> 
#include <queue> 
#include <string> 
#include <cstring> 
#include <map> 
#include <stack> 
#include <set> 
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
//orz yht
using namespace std;
int n;
vector<pair<ll,int> >v;
map<ll,int>mp;
vector<pair<int,int> > ans;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	ll x;
    	cin>>x;
    	mp[x]=i;
    	v.push_back(make_pair(x,i));
	}
	sort(v.rbegin(),v.rend());
	vector<int>sz(n,1);
	vector<ll>dp(n,0);
	for(auto x : v){
		if(x.first!=v.back().first){
			if(sz[x.second]*2>=n){
				cout<<-1;
				
				return 0;
			}
			ll need=x.first-(n-2*sz[x.second]);
			if(!mp.count(need)){
				cout<<-1;
				return 0;
			}
			ll par=mp[need];
			dp[par]+=dp[x.second]+sz[x.second];
			sz[par]+=sz[x.second];
			ans.push_back(make_pair(x.second+1,par+1));
		}
	}
	if(dp[v.back().second]!=v.back().first){
		cout<<-1;
		return 0;
	}
	for(auto x : ans)
	cout<<x.first<<" "<<x.second<<endl;
	return 0;
}