#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    ll N;
    cin>>N;
    int h, n, w;
    for(int i=1;i<=3500;i++)
    {
        for(int j=1;j<=3500;j++)
        {
            ll divisor=4*i*j-N*i-N*j;
            ll divident=N*i*j;
            if(divisor==0)
            {
                continue;
            }
            ll w=divident/divisor;
            if(w>0&&(divident%divisor)==0&&divisor>0)
            {
                cout<<i<<" "<<j<<" "<<w<<endl;
                return 0;
            }
        }
    }



    return 0;
}