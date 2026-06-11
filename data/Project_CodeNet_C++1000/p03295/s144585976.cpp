#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int main(){
	int n,m;
	cin>>n>>m;
	vector<pi>edge;
	while(m--){
		int a,b;
		cin>>a>>b;
		edge.push_back(pi(a,b));
	}
	sort(edge.begin(),edge.end());
	int fin = edge[0].second;
	int ret = 0;
	for(int i=0; i<edge.size(); i++){
		if(edge[i].first<fin){
			fin = min(fin,edge[i].second);
		}
		else{
			ret++;
			fin = edge[i].second;
		}
	}
	cout<<ret+1;
}