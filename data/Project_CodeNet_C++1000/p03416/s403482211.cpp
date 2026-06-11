#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a,b,cnt=0,j,ar[10],i;
	cin>>a>>b;
	for(;a<=b;a++)
	{
		i=a;
		j=0;
		while(i>0)
	  	{
			ar[j]=i%10;
			i/=10;
			j++;
		}
		if(ar[0]==ar[4]&&ar[1]==ar[3])
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}