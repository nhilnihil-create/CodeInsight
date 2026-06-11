#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a,b,k,c=0;
    while(cin>>a>>b>>k)
    {
        c=0;
        int i;
        for(i=min(a,b);i>=1;i--)
        {
            if(a%i==0&&b%i==0)
            {
                c++;
                if(c==k)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
}
