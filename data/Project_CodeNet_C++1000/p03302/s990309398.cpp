#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int x=a+b;
	int y=a*b;
	if(x==15) cout<<"+"<<endl;
	else if(y==15) cout<<"*"<<endl;
	else cout<<"x"<<endl;
 	return 0;
}
