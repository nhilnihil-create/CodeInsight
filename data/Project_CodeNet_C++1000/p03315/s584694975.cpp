#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int im=0;
	string s;
	cin>>s;
	int ss=s.size();
	for(int t=0;t<ss;t++) 
	{
		char symbol=s.at(t);
		if(symbol=='+')
		im++;
		else
		im--;
	}
	cout<<im<<endl;
}