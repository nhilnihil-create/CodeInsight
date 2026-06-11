#include <iostream>

using namespace std;

int main()
{
    int a,n,b,c;
    cin>>n>>a;
    if(a*1>n)
        {
            cout<<"Yes";
        }
    else
        {
            if(n%500==0)
        {
            cout<<"Yes";
        }
        else if(n%500!=0&&a==0)
        {
            cout<<"No";
        }
        else if(n%500!=0)
        {
            b=n%500;
            if(b*1<=a*1)
            {
                cout<<"Yes";
            }
            else if(b*1!=a*1)
            {
                cout<<"No";
            }
        }
    }

}