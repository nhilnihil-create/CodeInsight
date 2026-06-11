#include <bits/stdc++.h>
using namespace std;
int a[1000007],n,id;
int main()
{
	cin>>n;
	int maxx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxx){
			maxx=a[i];
			id=i;
		}
	}
	int mid=maxx/2+(maxx%2==1?1:0),ans,cnt=1999999999;
	for(int i=1;i<=n;i++){
		if(i==id) continue;
		if(abs(mid-a[i])<=cnt){
			cnt=abs(mid-a[i]);
			ans=a[i];
		}
	}
	cout<<maxx<<" "<<ans;
}
