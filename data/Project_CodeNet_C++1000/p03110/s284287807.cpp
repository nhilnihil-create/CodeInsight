#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
     double s=0;
    while(t--)
    {

        double x;
        string str;
        cin>>x;
        cin>>str;
        if(str=="BTC")
            s=s+x*380000;
         else
            s=s+x;
    }
    cout<<s;
}
