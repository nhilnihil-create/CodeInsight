#include<bits/stdc++.h>
using namespace std;
long long ans,n,k,num1,num2;
int main(){
	cin>>n>>k;
	num1=n/k;
	ans+=num1*num1*num1;
    if(k%2==0) num2=n/(k/2)-n/k;
    ans+=num2*num2*num2;
    cout<<ans;
	return 0;
}