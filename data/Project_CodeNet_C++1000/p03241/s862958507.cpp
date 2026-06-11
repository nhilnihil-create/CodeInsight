#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long  n, m, d, c, i;
    cin>>n>>m;
    d=m/n;
    c=m%n;
    for(i=d; i>0 ;i--)
    {
        if(c%i==0)
        {
            cout<<i<<endl;
            return 0;
        }
        c+=n;
    }
}