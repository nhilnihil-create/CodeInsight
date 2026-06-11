#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int n,ans=0;
	cin>>n;
	int A[n]={};
	for(int i=0;i<n;i++)cin>>A[i];
	int flag=1;
	while(flag){
		flag=0;
		for(int j=n-1;j>=1;j--){
			if(A[j]<A[j-1]){
				swap (A[j],A[j-1]);
				flag=1;
			}
		}
	}
	int i=n-1;
	while(i-1>=0){
        ans+=A[i];
		ans-=A[i-1];
		i=i-2;
    }
	if(i==0)ans+=A[0];
	cout<<ans<<endl;
}