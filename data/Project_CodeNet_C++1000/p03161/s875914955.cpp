#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	if(k>=n){
	cout<<v[n-1]-v[0];
	}
	else{
	vector<int> ans(n);
	ans[0]=0;
	for(int i=1;i<=k;i++){
		ans[i]=abs(v[i]-v[0]);
	}
	for(int i=k+1;i<n;i++){
		ans[i]=INT_MAX;
		for(int j=1;j<=k;j++){
			int y=abs(v[i]-v[i-j])+ans[i-j];
			ans[i]=min(ans[i],y);
		}
	}
	cout<<ans[n-1];
	}
}