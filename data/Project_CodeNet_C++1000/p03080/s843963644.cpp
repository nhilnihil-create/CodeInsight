#include <iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	int r_total=0,b_total=0;
	for (int i=1;i<=a;i++)
	{
		char s;
		cin>>s;
		if (s=='B')  b_total++;
		else if (s=='R')  r_total++;
	}
	if (b_total<r_total)  cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}