#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a,b;
    cin>>a>>b;
    if(a==b)
    {
    	cout<<"="<<endl;
    	return 0;
	}
	if(a<b)
	{
		cout<<"<"<<endl;
		return 0;
	}
	cout<<">"<<endl;
	return 0;
}