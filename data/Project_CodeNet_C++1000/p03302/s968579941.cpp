#include<bits/stdc++.h>
using namespace std;


int main()
{
	int a,b;
	cin>>a>>b;
	if(a*b==15) cout<<"*";
	if(a+b==15) cout<<"+";
	if(a+b!=15&&a*b!=15) cout<<"x";
    return 0;
}