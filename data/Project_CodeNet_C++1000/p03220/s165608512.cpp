#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<int,double>m;
    map<int,double>:: iterator itr;
    double n,t,a,h[1001],chk[1001];
    cin>>n;
    cin>>t>>a;
    for(int i=0; i<n; i++)
    {
        cin>>h[i];
        double equ=t-(.006*h[i]);
        if(equ>=a)
            m[i+1]=equ-a;
        else
            m[i+1]=a-equ;
    }
    double res=100000;
    for(itr=m.begin(); itr!=m.end(); itr++)
    {
        res=min(res,itr->second);
    }
    for(itr=m.begin(); itr!=m.end(); itr++)
    {
        if(itr->second==res)
        {
            cout<<itr->first;
            break;
        }
    }
    return 0;
}
