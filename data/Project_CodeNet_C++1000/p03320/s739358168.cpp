#include<bits/stdc++.h>
using namespace std;
long long n,ans,t=1,t2,x2;
double dl(long long x)
{
	t2=0; 
	x2=x;
    while(x!=0) 
	{
		t2=t2+x%10ll;
		x/=10ll;
	}
    return (x2*1.0)/(t2*1.0);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        while(1)
		{
            if(dl(ans+t)>dl(ans+t*10ll))
            {
                t*=10ll;
            }
            else
            {
            	break;
			}
        }
        ans+=t;
        cout<<ans<<endl;
    }
} 