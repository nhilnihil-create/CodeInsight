#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<cmath>
#include<set>
#include<algorithm>
#define int long long int
#define mod 1000000007
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a,b;
	cin>>a>>b;
	if(b-a<=10)
	{
		int answer=0;
		int j;
		for(j=a;j<=b;j++)
		    answer^=j;
		cout<<answer<<endl;
	}
	else
	{
		int answer=0;
		while(b%4!=3)
		{
			answer^=b;
			b--;
		}
		while(a%4!=0)
		{
			answer^=a;
			a++;
		}	
		cout<<answer<<endl;
	}
}
