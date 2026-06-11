#include <bits/stdc++.h>
#define pi 3.14159
#include <map>
#include <iterator>
using namespace std;
int main()
{
	long long int a,n,i,k,c=0;
	double b=0;
	cin>>n>>k;
	
	for(i=1;i<=n;i++)
		{	
		a=0;
			while(1)
			{
				if(i*pow(2,a)>=k)
					break;
				else
					a++;
			}		
			b+=pow(0.5,a);
		}

	cout<<setprecision(14)<<b/n<<endl;
	}