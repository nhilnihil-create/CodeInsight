#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[10001],b[10001];
	cin>>n;
	long long cnt=0;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	for (int i=0;i<n;i++){
		if (b[i]>a[i]) cnt+=(b[i]-a[i])/2;
		else cnt-=a[i]-b[i];
	}
	if (cnt<0) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}