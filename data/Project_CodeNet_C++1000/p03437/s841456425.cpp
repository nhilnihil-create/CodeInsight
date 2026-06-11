#include<iostream>
using namespace std;
long long x,y;
int main()
{
	cin>>x>>y;
	if(!(x%y)) cout<<-1;
	else cout<<x;
	return 0;
}