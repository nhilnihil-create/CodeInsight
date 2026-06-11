#include<bits/stdc++.h>
using namespace std;
long long t,s,p,n,h,a[100005],b[100005];
int main(){
	cin>>n>>h;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		t=max(t,a[i]);
	}
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(b[i]<t) break;
		s+=b[i];
		if(s>=h){
			cout<<i;
			return 0;
		}
		p=i;
	}
	long long ans=(h-s)/t;
	if((h-s)%t!=0)
	ans++;
	cout<<ans+p;
}