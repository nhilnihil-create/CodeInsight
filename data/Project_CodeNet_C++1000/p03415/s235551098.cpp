#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s[3],a;

	for(int i=0;i<3;i++)
		cin>>s[i];

	a+=s[0][0];
	a+=s[1][1];
	a+=s[2][2];

	cout<<a<<endl;

	return 0;
}