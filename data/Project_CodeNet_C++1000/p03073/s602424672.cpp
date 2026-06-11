#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{

    string s,ss,sss;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(i&1)
        {
            ss+="0";
        }
        else
        {
            ss+="1";
        }
    }
    for(int i=0; i<s.size(); i++)
    {
        if(i&1)
        {
            sss+="1";
        }
        else
        {
            sss+="0";
        }
    }
    ll cnta=0;
    ll cntb=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!=ss[i])
        {
            cnta++;
        }
        if(s[i]!=sss[i])
        {
            cntb++;
        }
    }
    cout<<min(cnta,cntb)<<endl;

}
