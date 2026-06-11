#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c[5];
	cin>>a>>b;
	c[1]=a+b;
	c[2]=a-b;
	c[3]=a*b;
	sort(c+1,c+4);
	cout<<c[3];
	return 0;
}
