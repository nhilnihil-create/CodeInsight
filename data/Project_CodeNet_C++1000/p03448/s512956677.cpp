#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int func(int x)
{
    if(x%2==0)
    {
        return x/2;
    }
    else
    {
        return 3*x+1;
    }
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int x;
    cin>>x;
    int count = 0;
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            for(int k=0;k<=c;k++)
            {
                if(i*500+j*100+k*50==x)
                {
                    count++;
                }
            }
        }
    }

    cout<<count<<endl;
    return 0;
}