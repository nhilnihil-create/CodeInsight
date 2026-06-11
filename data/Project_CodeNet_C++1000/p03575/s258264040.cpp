#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int p[55];
vector<pi>edge;
int u_find(int a){
	if(!p[a]) return a;
	return p[a] = u_find(p[a]);
}
void merge(int a,int b){
	a = u_find(a);
	b = u_find(b);
	if(a==b) return;
	p[a] = b;
}
bool solve(int num,int n){
	memset(p,0,sizeof(p));
	for(int i=0; i<edge.size(); i++){
		if(i!=num) merge(edge[i].first,edge[i].second);
	}
	for(int i=1; i<=n; i++){
		if(u_find(1)!=u_find(i)) return true;
	}
	return false;
}
int main(){
	int n,m;
	cin>>n>>m;
	
	while(m--){
		int a,b;
		cin>>a>>b;
		edge.push_back(pi(a,b));
	}
	int ret = 0;
	for(int i=0; i<edge.size(); i++){
		if(solve(i,n)) ret++;
	}
	cout<<ret;
}