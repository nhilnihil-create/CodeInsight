#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,sum=0;
	cin>>n;
	while(n>0){
		if(n%10==2){
			sum++;
		}
		n=n/10;
	}
	cout<<sum<<endl;
	return 0;
}