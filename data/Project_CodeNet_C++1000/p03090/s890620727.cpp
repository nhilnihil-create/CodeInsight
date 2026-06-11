#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;cin>>N;
	int ng=((N%2)?N:N+1);
	vector<pair<int,int>> ans;
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;++j){
			if(j==ng-i)continue;
			ans.push_back(make_pair(i,j));
		}
	}
	cout<<ans.size()<<endl;
	for(auto x:ans){
		cout<<x.first<<' '<<x.second<<endl;
	}
}