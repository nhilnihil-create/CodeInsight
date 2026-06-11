#include <bits/stdc++.h>

using namespace std;

long long n,P,sol;
int prime[1000050],lg;
bitset<1000050>t;

void Ciur()
{
    int i,j;
    for(i=3;i*i<1000050;i+=2)
        if(t[i]==0)
            for(j=i*i;j<1000050;j=j+2*i)
                t[j]=1;
    lg=1;
    prime[1]=2;
    for(i=3;i<1000050;i+=2)
        if(t[i]==0)
            prime[++lg]=i;
}

long long Lgput(long long a,int x)
{
    long long p=1;

    while(x)
    {
        if(x%2)
            p=p*a;
        x/=2;
        a=a*a;
    }
    return p;
}

void Desc()
{
    int d=2,cnt;

    for(int i=1;P>1 && 1LL*d*d<=P;i++)
    {
        if(P%d==0)
        {
            cnt=0;
            while(P%d==0)
            {
                cnt++;
                P/=d;
            }
            sol=sol*Lgput(d,cnt/n);
        }
        d=prime[i+1];
    }

    if(P>1)
        sol=sol*Lgput(P,1/n);
}



int main()
{
    cin>>n>>P;

    sol=1;
    Ciur();
    Desc();

    cout<<sol;
    return 0;
}
