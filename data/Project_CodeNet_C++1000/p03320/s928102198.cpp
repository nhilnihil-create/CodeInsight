#include<bits/stdc++.h>
using namespace std;
long long Total;
long long Ans;
inline double GetSum(long long X)
{
	register long long Return;
	Return=0;
	register long long Y;
	Y=X;
	while(X)
	{
		Return+=X%10;
		X/=10;
	}
	return 1.0*Y/Return;
}
int main(void)
{
	register long long i;
	cin>>Total;
	i=1;
	while(Total--)
	{
		while(true)
		{
			if(GetSum(i+Ans)>GetSum(i*10+Ans))
			{
				i*=10;
			}
			else
			{
				break;
			}
		}
		Ans+=i;
		cout<<Ans<<endl;
	}
	return 0;
}
