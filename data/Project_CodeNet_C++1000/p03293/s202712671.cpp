#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    bool ok=false;
    for(int i=0;i<t.size();i++)
    {
        if(s==t)
        {
            ok=true;
            break;
        }
        t=t.back()+t.substr(0,t.size()-1); /// substr(string,start,length)

    }
       if(ok)
       {
           cout<<"Yes";
       }
       else
       {
           cout<<"No";
       }
}
