#include<bits/stdc++.h>
using namespace std;
int p[100005];
bool visited[100005];
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
int main(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b,z;
		cin>>a>>b>>z;
		merge(a,b);
	}
	int ret = 0;
	for(int i=1; i<=n; i++){
		int r = u_find(i);
		if(visited[r]) continue;
		visited[r] = true;
		ret++;
	}
	cout<<ret;
}