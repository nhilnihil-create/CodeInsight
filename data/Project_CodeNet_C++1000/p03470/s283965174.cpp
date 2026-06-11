#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int n,A[101]={},ans=0,d;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>d;
		A[d]=1;
	}
	for(int i=0;i<=100;i++){
		if(A[i]==1)ans++;
	}
	cout<<ans<<endl;
	
}