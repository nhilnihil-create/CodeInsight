#include <bits/stdc++.h>
using namespace std;

int prime[100010];
int prime2017[100010];
int sp[100010];

bool isprime(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for(int i=2;i<100010;i++)prime[i]=1;

    for(int i=2;i<100010;i++)
    {
        if(prime[i]==0)continue;

        if(isprime(i))
        {
            for(int j=i*2;j<100010;j+=i)
            {
                prime[j]=0;
            }

            if(prime[(i+1)/2]==1)prime2017[i]=1;
        }
    }

    for(int i=0;i<100010;i++)sp[i+1]=sp[i]+prime2017[i];

    int q;cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r;cin>>l>>r;

        cout<<sp[r+1]-sp[l]<<"\n";
    }

    return 0;
}
