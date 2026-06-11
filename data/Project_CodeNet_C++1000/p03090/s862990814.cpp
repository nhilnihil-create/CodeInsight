#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
typedef pair<int,int> pii;
vector<pii> ans;
int n;
int main(){
	ios::sync_with_stdio(false);
	int i,j;
	cin>>n;
	if(n&1){
		for(i=1;i<n;i++)
			ans.push_back(make_pair(i,n));
		n--;
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(i+j!=n+1)
				ans.push_back(make_pair(i,j));
	cout<<(int)ans.size()<<endl;
	for(i=0;i<(int)ans.size();i++)
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
	return 0;
}