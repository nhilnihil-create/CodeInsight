#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<char> c(100,' ');
	int i=0;
	while(n!=0)
	{
		int am=abs(n%2);
		int n2=n;
		if(am==1)
		{
			c.at(i)='1';
		}
		else
		{
			c.at(i)='0';
		}
		i++;
		n /= (-2);
		if(am==1&&n>0)
		{
			n++;
		}
		if(n==0&&n2==-1)
		{
			c.at(i)='1';
			i++;
		}
	}
	for(int j=0;j<i;j++)
	{
		cout << c.at(i-j-1);
	}
	if(c.at(0)==' ')
	{
		cout << '0';
	}
    cout << endl;
	return 0;
}
