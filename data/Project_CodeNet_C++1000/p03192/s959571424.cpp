#include<bits/stdc++.h>
using namespace std;
int n,num=0;
int main(){
	cin>>n;
	while(n!=0){
		if(n%10==2)num++;
		n/=10;
	}
	cout<<num<<endl;
	
	
}