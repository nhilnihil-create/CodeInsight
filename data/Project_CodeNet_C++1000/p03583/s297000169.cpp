#include<bits/stdc++.h>
using namespace std;
long long arr[1000000],arr1[1000000];
map <long long, long long > cnt;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    long long n,i,j,k;
    long double n1,a,b,c;
	cin>>n;
	if (n%2==0)
	{
		cout<<n<<" "<<n<<" "<<n/2<<endl;
		return 0;
	}
	if (n%4==3)
	{
		for (i=1;i<=3500;i++)
		{
			if (4*i>n)
			{
				cout<<2*n*i<<" "<<i<<" "<<2*n*i<<endl;
				return 0;
			}
		}
	}
	//cout<<n1<<endl;
	for (i=1;i<=3500;i++)
	{
		if (4*i>n)
		{
			for (j=1;j<4*i-n;j++)
			{
				if ((n*i)%(j)==0 && (n*i)%(4*i-n-j)==0)
				{
					cout<<n*i/(4*i-n-j)<<" "<<n*i/j<<" "<<i<<endl;
					return 0;
				}
			}
		}
	}
}