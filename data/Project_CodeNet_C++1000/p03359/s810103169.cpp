#include <iostream>

using namespace std;

int main()
{
	int x,y;
	
	cin>>x>>y;
	
	int ans=x;
	
	if(y<x)
		ans--;
	
	cout<<ans;
	return 0;
}
