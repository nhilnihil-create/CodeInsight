#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t="";
    int i=0,m=1;
    while(m<=3)
    {
        cin>>s;
        t=t+s[i];
        i++;
        m++;
    }
    cout<<t<<endl;
}

