#include<bits/stdc++.h>
using namespace std;
long long l,sum,sum1;
string s;
int main()
{
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		sum1+=s[i]-'0';
		if(s[i]=='1'&&i==0) continue;
		  else if(i==0) {sum+=(s[i]-'0'-1);continue;}
		sum+=9;
	}
	cout<<max(sum1,sum)<<"\n";
	return 0;
 } 