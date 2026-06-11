#include<bits/stdc++.h>
using namespace std;
const int N=22;
vector<pair<pair<int,int>,int> > ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l,cnt;
	cin>>l;
	n=__lg(l)+1;
	for(i=1;i<n;i++){
		ans.push_back({{i,i+1},0});
		ans.push_back({{i,i+1},(1<<(i-1))});
	}
	l-=(1<<(n-1));
	cnt=(1<<(n-1));
	while(l){
		j=__lg(l);
		ans.push_back({{j+1,n},cnt});
		l-=(1<<j);
		cnt+=(1<<j);
	}
	cout<<n<<' '<<ans.size()<<'\n';
	for(i=0;i<ans.size();i++){
		cout<<ans[i].first.first<<' '<<ans[i].first.second<<' '<<ans[i].second<<'\n'; 
	}
}