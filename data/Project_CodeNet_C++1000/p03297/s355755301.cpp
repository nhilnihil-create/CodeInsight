#include <bits/stdc++.h>
using namespace std;
#define LL long long 


void Y()
{
	printf("Yes\n");
}
void N()
{
	printf("No\n");
}

LL gcd(LL x,LL y)
{
	return x%y==0?y:gcd(y,x%y);
}
int main()
{
	//freopen("acmin","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		LL a,b,c,d;
		cin>>a>>b>>c>>d;

		if(b>d)
		{
			N();
			continue;
		}
		else if(b==d)
		{
			if(c>=b)
				Y();
			else
			{
				if(a<=c)
					N();
				else
				{
					LL e = (a-c)%b+c;
					if(e<b)
						N();
					else
						Y();
				}
			}
		}
		else
		{
			if(c>=b)
			{
				if(a>=b)
					Y();
				else
					N();
			}
			else
			{
				if(a<b)
					N();
				else
				{
					if((a-c)%b)
						a= (a-c)%b+c-b;
					else
						a=c;
					if(a<0)
					{
						N();
					}
					else
					{
						LL x = d%b;
						if(!x)
							Y();
						else{
							x = gcd(x,b);
							LL e = (b-a)/x,f = (c-a)/x,flag=0;
							for(LL i=f;i<=e;i++)
								if(c-a<i*x&&i*x<b-a)
								{
									flag=1;
									break;
								}
							if(flag)
								N();
							else 
								Y();

						}
					}
				}
			}

		}
	}
	return 0;
}
