#include<bits/stdc++.h>
using namespace std;
int a,b,c,s;
int main(){
	cin>>a>>b>>c;
	int d=max(max(a,b),c);
	d=d*3;
	d-=a;
	d-=b;
	d-=c;
	if(d%2==0)
	s=d/2;
	else
	s=(d+3)/2;
	cout<<s;
 } 
