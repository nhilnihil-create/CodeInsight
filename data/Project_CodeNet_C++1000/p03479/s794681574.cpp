#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main()
{
    ull x,y,i=1,c=1;
    cin>>x>>y;
    for(i=x;i<=y;i*=2)
    {
        if(i*2 <=y)
        {
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}
