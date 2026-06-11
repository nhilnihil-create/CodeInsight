#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	string s;
	cin>>s;

	int W =0;
	long long sum = 0;

	for(int  i = (int)s.length()-1;i>=0;i--)
	{
		  if(s[i]=='W')
		  	W++;
		  else
		  	sum+=W;
	}
	cout<<sum<<endl;
}