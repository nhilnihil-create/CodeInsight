#include<iostream>
#include<algorithm>
using namespace std;
main(){
	int a,b,c;
	int oo=0;
	cin>>a>>b>>c;
	if(b<c){
	oo+=(2*b);
	c-=b;
   if(a<c)
	oo+=(a+1);
	else oo+=c;
	}
   else if(b==c)oo=2*c;
   else oo=c+b;
	cout<<oo;
}