#include<iostream>
using namespace std;
int m,s,l,i,a;
main(){
	cin>>a;
	for(i=0;i<a;i++){
		cin>>l;
		if(m<l)m=l;
		s+=l;}
	puts(s>m*2?"Yes":"No");}
