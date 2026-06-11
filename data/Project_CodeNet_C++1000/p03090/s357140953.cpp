#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<pair<int,int>>edges;
	int sum=n;
	if(n%2==0)sum++;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(i+j==sum)continue;
			edges.push_back({i,j});
		}
	}
	cout<<int(edges.size())<<'\n';
	for(auto x : edges)cout << x.first << ' ' << x.second << '\n';
}
