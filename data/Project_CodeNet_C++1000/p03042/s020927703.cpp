#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,r,d,c=0,f=0;
    cin>>n;
    r=n%100;
    d=n/100;
    if(r>=1 && r<=12 )
    {
        c++;
    }
    if(d>=1 && d<=12 )
    {
        f++;
    }

    if( c>0 && f>0)
    {

        cout<<"AMBIGUOUS"<<endl;

    }
    else if( c>0)
    {
        cout<<"YYMM"<<endl;
    }

    else if( f>0)
    {
        cout<<"MMYY"<<endl;
    }

    else
    {
        cout<<"NA"<<endl;
    }

    return 0;

}
