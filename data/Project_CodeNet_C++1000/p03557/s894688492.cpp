#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	long long n,ans=0;
	long long a[100005],b[100005],c[100005],d[100005]={};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	
	for(int i=n-1;i>=0;i--){
		auto d1=lower_bound(c,c+n,b[i]+1)-c;
		d[i]+=n-d1;
		d[i]+=d[i+1];
	}
	for(int i=0;i<n;i++){
		auto m=lower_bound(b,b+n,a[i]+1)-b;
		ans+=d[m];
	}
	/*
	for(int i=0;i<n;i++){
		auto m=upper_bound(c,c+n,b[i])-c;
		auto l=lower_bound(a,a+n,b[i])-a;
		m=n-m;
		ans+=m*l;
	}
	*/
	cout<<ans<<endl;
    return(0);
}