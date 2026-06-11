#include<bits/stdc++.h>
using namespace std;
string s,yl="AKIHABARA";
int n,l;
int main()
{
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==yl[n])
            n++;
        else
        {
            if(i>0)
            if(s[i]==s[i-1])
            {
                cout<<"NO"<<endl;
                exit(0);
            }
            if(yl[n]=='A')n++,i--;
            else
            {
                cout<<"NO"<<endl;
                exit(0);
            }
        }
    }
    l=s.length();
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='A')l--;
    }
    if(l==5)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}