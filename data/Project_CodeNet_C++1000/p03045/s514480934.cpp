#include<bits/stdc++.h>
using namespace std;
int n,m,p[1<<17],i,x,y,z,t;
int f(int x){
	if(p[x]==x)return x;
	return p[x]=f(p[x]);
}
int main(){
	cin>>n>>m;
	t=m;
	for(i=1;i<=n;i++)p[i]=i;
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(f(x)==f(y))t--;
		else p[f(x)]=f(y);
	}
	cout<<n-t;
	return 0;
}
