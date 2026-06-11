#include <iostream>
#include <cmath>
#define endl "\n"
using namespace std;
int main(int argc, char const *argv[])
{
	int n,a,b;
	cin>>n>>a>>b;
	if(abs(a-b)&1)
		cout<<"Borys"<<endl;
	else
		cout<<"Alice"<<endl;
	return 0;
}
