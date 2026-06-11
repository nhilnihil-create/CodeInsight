#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int b,k;
int main(){
	string a;
	cin>>b>>k;
	cin>>a;
	if(a[k-1]==	'A')
		a[k-1]='a';
	if(a[k-1]==	'B')
		a[k-1]='b';
	if(a[k-1]==	'C')
		a[k-1]='c';
		
	cout<<a;
}