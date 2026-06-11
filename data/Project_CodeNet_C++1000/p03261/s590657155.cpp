#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    set<string>t;
    bool flag=true;
    bool flag1=true;
    string s1;
    for(i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(flag==false)
        {
            if(s[0]!=s1[s1.size()-1])
            {
            flag1=false;
            }
        }
        s1=s;
        t.insert(s);
        flag=false;
    }
    if(flag1==false)
    {
        cout<<"No";
        return 0;
    }
    if(t.size()!=n)
    {
        cout<<"No";
    }
    else
    {
        cout<<"Yes";
    }
}
