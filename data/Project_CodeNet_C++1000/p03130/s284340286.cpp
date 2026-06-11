#include <bits/stdc++.h>
using namespace std;

int main(){
	map<int,int> m;
	for(int i=0;i<3;i++){
		int u,v;cin>>u>>v;
		m[u] += 1;
		m[v] += 1;
	}
	for(auto x: m) if(x.second > 2){
		cout<<"NO"<<endl;
		return 0;
	}

	cout<<"YES"<<endl;
	return 0;
}