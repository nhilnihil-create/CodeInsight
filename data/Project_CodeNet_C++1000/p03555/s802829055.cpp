#include <iostream>
using namespace std;
int main()
{
	string x,y;
	cin>>x>>y;
	if(x[0]==y[2]&&x[1]==y[1]&&x[2]==y[0])
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}


	return 0;
}