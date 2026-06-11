#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin>>n;
	long long s1=0,s2=0,ans=0;
	long long a[n+1],b[n+1],c[n+1];
	long long h=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s1+=a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		s2+=b[i];
		if(b[i]>a[i]){
			h+=b[i]-a[i];
			ans++;
		}
		c[i]=a[i]-b[i];
	}
	if(s2>s1){
		cout<<-1<<endl;
		return 0;
	}
	sort(c+1,c+n+1);
	if(h<=0){
		cout<<0<<endl;
		return 0;
	}
	for(int i=n;i>=1;i--){
		h-=c[i];
		//cout<<c[i]<<endl;
		if(h<=0){
			cout<<++ans<<endl;
			return 0;
		}
		++ans;
	}
}
//