#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,a,b,c[10009],d[10009],num;
vector<int> e[10009];

void dfs(int node){
	d[node]=c[num];
	num++;
	for(int i=0;i<e[node].size();i++){
		if(!d[e[node][i]])dfs(e[node][i]);
	}
}

int main(){
    cin>>n;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}int M=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
		M+=c[i];
	}
	sort(c,c+n,greater<int>());
	cout<<M-c[0]<<endl;
	dfs(1);
	for(int i=1;i<=n;i++){
		if(i-1)cout<<" ";
		cout<<d[i];
	}
	cout<<endl;
    return 0;
}
