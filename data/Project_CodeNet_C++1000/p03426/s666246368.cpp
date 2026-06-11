#include<bits/stdc++.h>
using namespace std;
int m,n,k,t,o,l,r,d[90001];
int main(){
	cin>>m>>n>>k;
	vector<pair<int,int> > a(90001);
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++){
		cin>>t;
		a[t].first=i;
		a[t].second=j;
	}
	for(int i=k+1;i<=m*n;i++)
	d[i]=d[i-k]+fabs(a[i].first-a[i-k].first)+fabs(a[i].second-a[i-k].second);
	cin>>o;
	for(int i=0;i<o;i++){
		cin>>l>>r;
		if(l==r)
		cout<<0<<endl;
		else
		cout<<d[r]-d[l]<<endl;
	}
} 