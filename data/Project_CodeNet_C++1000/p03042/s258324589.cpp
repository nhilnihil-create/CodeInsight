#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int i=0,ans,s,st,nd;
    cin>>s;
    nd=s%100;
    st=s/100;
    if((0<st&&st<13)&&(0<nd&&nd<13))
    {
        cout<<"AMBIGUOUS";
    }
    
    else if((0<nd) && (nd<13))
    {
         cout<<"YYMM";
    }
   
    else if((0<st)&&(st<13))
    {
        cout<<"MMYY";
    }
    else
    {
        cout<<"NA";
    }
    return 0;
}