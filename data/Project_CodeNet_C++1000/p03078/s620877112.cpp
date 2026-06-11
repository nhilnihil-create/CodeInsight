#include<bits/stdc++.h>
#define    ll   long long int
#define    sz   200010
#define    md   1000000007
#define    py   printf("YES\n")
#define    pn   printf("NO\n")

using namespace std;

ll ax[sz];
ll bx[sz];
ll cx[sz];
ll ara[sz];
priority_queue<ll>q;


int main()
{

    ll x,y,z,n,i,j,k,p,s=0,c,a,b,d,o;

    scanf("%lld %lld %lld %lld",&x,&y,&z,&p);

    for(i=1; i<=x; i++)
    {
        cin>>ara[i];
    }
    sort(ara+1,ara+x+1);

    j=1;

    for(i=x; i>=1; i--)
    {
        ax[j]=ara[i];
        j++;
    }


    for(i=1; i<=y; i++)
    {
        cin>>ara[i];
    }
    sort(ara+1,ara+y+1);

    j=1;

    for(i=y; i>=1; i--)
    {
        bx[j]=ara[i];
        j++;
    }



    for(i=1; i<=z; i++)
    {
        cin>>ara[i];
    }
    sort(ara+1,ara+z+1);
    j=1;

    for(i=z; i>=1; i--)
    {
        cx[j]=ara[i];
        j++;
    }



    for(i=1; i<=x; i++)
    {
        for(j=1; j<=y; j++)
        {
            for(k=1; k<=z; k++)
            {
                q.push(ax[i]+bx[j]+cx[k]);
                c=(i)*(j)*(k);

                if(c>p)break;

            }
        }
    }


    while(p--)
    {
        d=q.top();
        cout<<d<<endl;
        q.pop();

    }

    return 0;
}
