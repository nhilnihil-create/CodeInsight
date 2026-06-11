#include<iostream>
using namespace std;
int main()
{
int a,b,k,m=0,j,t;
cin>>a>>b>>k;
if(a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    for( j=b;j>0;j--)
    {
        if(b%j==0&&a%j==0)
            m++;
           if(m==k)
              {

               cout<<j<<endl;
          return 0; }

    }


}
