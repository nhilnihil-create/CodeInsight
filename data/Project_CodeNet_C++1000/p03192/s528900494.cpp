#include<iostream>
using namespace std;
int n,s;
int main(){
cin>>n;
if(n/1000==2) s++;
if(n%1000/100==2) s++;
if(n%100/10==2) s++;
if(n%10==2) s++;
cout<<s;
	return 0;
}