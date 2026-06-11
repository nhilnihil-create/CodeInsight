#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a,b,k;
    cin>>a>>b>>k;

    for(int i=0;i<k;i++)
    {
        if(i%2==0)
        {
            a/=2;
            b+=a;
        }
        else
        {
            b/=2;
            a+=b;
        }
    }

    cout<<a<< " " << b;

    return 0;
}
