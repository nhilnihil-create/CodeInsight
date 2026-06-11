#include<iostream>
#include<cstring>
using namespace std;
char st[61];
int main()
{
	cin>>st;
	for(int i=0;i<strlen(st)-8;i++) cout<<st[i];
	cout<<endl;
}