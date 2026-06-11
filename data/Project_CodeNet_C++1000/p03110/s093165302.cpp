#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double tot,x,tk=0,bit=0;
    while(n--)
    {
        string str;
        cin>>x>>str;
        if(str=="JPY")
            tk+=x;
        else
            bit+=x;
    }
    tot=tk+(bit*380000.0);
    cout<<tot<<endl;
    return 0;
}
