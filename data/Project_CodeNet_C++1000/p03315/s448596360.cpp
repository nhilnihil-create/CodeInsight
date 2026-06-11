#include<bits/stdc++.h>
using namespace std;
int main()
{

long long a,b,c;
long long count=0;
string s;
cin>>s;

for (int i = 0; i < s.length(); ++i)
{
	/* code */
	if (s[i]=='+')
	{
		/* code */
		count++;
	}
	else
		count--;
}

cout<<count<<endl;
return 0;
}