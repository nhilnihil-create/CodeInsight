#include<bits/stdc++.h>                          
using namespace std;
int a,b,num1,num2,num3;
int main(){
    cin>>a>>b;
    num1=a-b;
    num2=a+b;
    num3=a*b;
    cout<<max(num3,max(num1,num2));
	return 0;
}