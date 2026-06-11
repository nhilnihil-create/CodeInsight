#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,s;
    cin>>a>>b>>c;
    s=a;
    d=0;
    while(d<c&&s<=b)
    {
        s+=a;
            d++;
    }
    cout<<d<<endl;
}
