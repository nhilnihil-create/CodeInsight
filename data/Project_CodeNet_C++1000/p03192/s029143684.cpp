#include<bits/stdc++.h>
using namespace std;
int main(){ 
	int a,sum=0;
	cin>>a;
    while(a!=0){
    	if(a%10==2) sum++;
    	a/=10;
    }
    cout<<sum<<endl;
	return 0;
}