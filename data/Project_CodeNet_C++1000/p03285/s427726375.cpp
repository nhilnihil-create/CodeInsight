#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp;
    cin>>n;
    temp=n;
   /* if(n<4||n<7)
    {
        cout<<"No";
        return 0;
    }*/
    if(n%4==0 || n%7==0)
    {
        cout<<"Yes";
        return 0;
    }
    else
    {
        while(temp>=11)
        {
            if((temp-7)%4==0)
            {
                cout<<"Yes";
                return 0;
            }
            else
            {
                temp=temp-7;
            }
        }
    }
    cout<<"No";
    return 0;

}
