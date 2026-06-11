#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    int flag=0;
    cin>>s>>t;
    for(int i=0;i<s.length();i++)
    {
        if(s==t)
        {   flag=1;
            break;
        }
        s=s.back() +s.substr(0,s.size()-1);    }
    if(flag==1)
    {
        cout<<"Yes"<<"\n";
    }
    else{
    cout<<"No"<<"\n";
    }
    return 0;
}