#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long n,a[300005],ans=0;

int main(){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];	
		int j=0,now=0,pp=0;
		for(int i=1;i<=n;i++){
			while((pp^a[j+1])==now+a[j+1]&&j<n){
			now+=a[j+1];
			pp = pp^a[j+1];
			j++;
			}
			if(pp==now)ans+=(j-i+1);
			now-=a[i];
			pp = pp^a[i];
		}
		cout<<ans<<endl;
}