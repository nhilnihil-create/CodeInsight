#include <bits/stdc++.h>
using namespace std;
int a[100005];

int main(){
	int n,k,i,ans=0;
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	n-=k,ans++;
	if(n%(k-1)) ans+=n/(k-1)+1;
	else ans+=n/(k-1);
	cout<<ans<<endl;
	return 0; 
}