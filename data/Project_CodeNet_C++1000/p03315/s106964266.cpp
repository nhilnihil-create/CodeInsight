#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a=0;
	for(int i=0; i < s.size(); i++)
	{
		if(s[i]=='+')
			a++;
		else
			a--;
	}
	cout<<a<<endl;
	return 0;
}
