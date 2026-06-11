#include<bits/stdc++.h>
#include <bitset>
using namespace std;

int main()
{
	
	
	
	int T,i,j,s,n;
	
	
	{
		int mn,mx,cnt=0;
		cin>>mn>>mx;

		string str1,str2;

		for(int i=mn;i<=mx;i++)
		{
			str1=to_string(i);
			str2=str1;
			reverse(begin(str2),end(str2));
			if(str2==str1)
				cnt++;
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
}
