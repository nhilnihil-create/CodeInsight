#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int tot;
	if(n&1){
		tot = n;
	}
	else	tot = n+1;
	vector<pair<int,int> > ans;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(i+j!=tot)
				ans.emplace_back(i,j);
	cout<<ans.size()<<'\n';
	for(auto it:ans)
		cout<<it.first<<' '<<it.second<<'\n';
}
