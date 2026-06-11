#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,k;
    cin>>a>>b>>c>>d>>e>>k;
    if(a-b>k || a-c>k || c-a>k|| a-d>k || d-a>k|| a-e>k || e-a>k || b-c>k || c-b>k || b-d>k || d-e>k || b-e>k || e-b>k || c-d>k || d-c>k || c-e>k || e-c>k || d-e>k || e-d>k)
    {
        cout<<":("<<endl;
        return 0;
    }
    else
        {
            cout<<"Yay!"<<endl;
            return 0;
        }
    }
