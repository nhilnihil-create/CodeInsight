#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,x[900],i,k,m,n,sum,temp,flag=0;
    cin >> a >> b;
    for(i=0; ;)
    {
        for(k=1; k<10; k++)
        {
            sum=k;
            for(m=0; m<10; m++)
            {
                sum*=10;
                sum+=m;
                temp=sum;
                for(n=0; n<10; n++)
                {
                   sum*=10;
                   sum+=n;
                   sum*=10;
                   sum+=m;
                   sum*=10;
                   sum+=k;
                   x[i]=sum;
                   sum=temp;
                   i++;
                }
                sum/=10;
            }
        }
        break;
    }
    for(i=0;i<900;i++)
    {
        if(x[i]>=a && x[i]<=b)
            flag++;
    }
    cout << flag;
    return 0;
}