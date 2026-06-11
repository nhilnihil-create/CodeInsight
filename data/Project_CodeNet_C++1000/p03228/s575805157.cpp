#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

int main()
{
    long long int a,b,k;
    cin>>a>>b>>k;
    for(int i=1;i<=k;i++)
    {
        if(i%2==0)
        {
            if(b%2==0)
            {
                a=a+(b/2);
                b=b-(b/2);
            }
            else
            {
                a=a+(b/2);
                b=b-1-(b/2);
            }
        }
        else
        {
            if(a%2==0)
            {
                b=b+(a/2);
                a=a/2;
            }

            else
            {
                b=b+(a/2);
                a=a-1-(a/2);
            }


        }
    }

    cout<<a<<" "<<b<<endl;

    return 0;
}
