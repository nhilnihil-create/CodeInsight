#include<iostream>
using namespace std;
int k[200000+5];
int s1[200000+5];
long long s[200000+5],ans;
int mid;
bool check(int mid,int l){
	return (s1[mid]^s1[l-1])==(s[mid]-s[l-1]);
}
int main(){
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+k[i];
	}
	for(int i=1;i<=n;i++){
		s1[i]=k[i]^s1[i-1];
	}
	for(int l=1;l<=n;l++){
		int s=l,t=n;
		while(s<t){
			 mid=(s+t+1)/2;
			if(check(mid,l)) s=mid;
			else t=mid-1;
		}
		ans+=s-l+1;
	}
	cout<<ans<<endl;
}