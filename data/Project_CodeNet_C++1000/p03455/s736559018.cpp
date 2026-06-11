#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int a,b;
	cin>>a>>b;
	if(a%2==0||b%2==0) cout<<"Even"<<endl;
	else cout<<"Odd"<<endl;
	return 0;
}