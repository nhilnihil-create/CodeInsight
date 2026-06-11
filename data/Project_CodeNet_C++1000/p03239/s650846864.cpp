#include<bits/stdc++.h>
using namespace std;
const int inf=1e5;
int main(){
	int n,T,c[100],t[100],cost=inf;
	cin>>n>>T;
	for(int i=0;i<n;i++){
		cin>>c[i]>>t[i];
		if(t[i]<=T) cost=min(cost,c[i]);
	}
	if(cost==inf) cout<<"TLE"<<endl;
	else cout<<cost<<endl;
	return 0;
}
