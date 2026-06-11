#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    double su=0,a;
    string s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>s;
        if(s=="JPY")
            su+=a;
        else
            su+=(380000.0*a);
    }
    cout<<su<<endl;
}
