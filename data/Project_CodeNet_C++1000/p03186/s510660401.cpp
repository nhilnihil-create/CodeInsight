#include<bits/stdc++.h>
using namespace std;

int main(){
	unsigned a,b,c;
	cin>>a>>b>>c;
	if(c>a+b)cout<<a+b*2+1;
	else cout<<b+c;
	return 0;
}