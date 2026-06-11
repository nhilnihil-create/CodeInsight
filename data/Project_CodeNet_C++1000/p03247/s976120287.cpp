#include <iostream>
#include <algorithm>
#include <cstdio>
#include<string>
#include<cstring>
using namespace std;
int m,n,l,a[1100000],b[1100000],d[50],q[10];
void print(int &xx,int &yy)
{
    for(int x=1;x<=l;x++)
    {
      if(abs(xx)>abs(yy))
      {
          if(xx>0)
          {
              cout<<"R";
              xx-=d[x];
          }
          else
          {
              cout<<"L";
              xx+=d[x];
          }
      }
    else
    {
        if(yy>0)
        {
            cout<<"U";
            yy-=d[x];
        }
        else
        {
            cout<<"D";
            yy+=d[x];
        }
    }
    }
}int main()
{
    cin>>m;
    for(int x=1;x<=m;x++)
    {
        cin>>a[x]>>b[x];
        q[(a[x]+b[x])%2]=1;
    }
    if(q[0]==1&&q[1]==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int x=30;x>=0;x--)
    {
        d[++l]=(1<<x);
    }
    if(q[0]==1)
    {
        d[++l]=1;
    }
    cout<<l<<endl;
    for(int x=1;x<l;x++)
    {
        cout<<d[x]<<" ";
    }
    cout<<d[l]<<endl;
    for(int x=1;x<=m;x++)
    {
      print(a[x],b[x]);
  //    cout<<a[x]<<" "<<b[x]<<endl;
      cout<<endl;
    }
    return 0;
}
