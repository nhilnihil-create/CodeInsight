#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
int a[N];
signed main(){
	int n;cin>>n;
	int sum=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> v;
	for(int i=1;i<=n+1;i++){
		if(a[i]==a[i+1]) sum++;else v.push_back(sum),sum=1;
	}
	int ans=0;
	for(int i=0;i<v.size();i++){
		//cout<<v[i]<<" ";
		ans+=v[i]/2;
	} 
//	cout<<'\n';
	cout<<ans;
	return 0;
}