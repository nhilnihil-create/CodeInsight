#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;	cin>>n;
	vector<int> D(n+2);		D[0]=0;	D[n+1]=24;
	for(int i=1;i<=n;i++)cin>>D[i];
	sort(D.begin(), D.end());

	for(int i=1;i<=n;i++){
		if(D[i]==0)continue;

		if(i%2==0)D[i]=(24-D[i]);
	}sort(D.begin(), D.end());

	int ans=100;
	for(int i=1;i<=n+1;i++){
		ans=min(ans, D[i]-D[i-1]);
	}

	cout<<ans<<endl;
	return 0;
}
