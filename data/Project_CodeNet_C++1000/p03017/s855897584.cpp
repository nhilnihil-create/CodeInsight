#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,d,ans=0;
    cin>>n>>a>>b>>c>>d;
    string t;
    cin>>t;
    string s='#'+t+'#';
    if(c>d)
    {
        for(int i=b;i<=d;i++)
        {
            if(s[i-1]=='.'&&s[i+1]=='.'&&s[i]=='.') ans++;
        }
        if(ans==0)
        {
            cout<<"No";
            return 0;
        }
    }
    for(int i=b;i<d;i++)
    {
        if(s[i]=='#'&&s[i+1]=='#')
        {
            cout<<"No";
            return 0;
        }
    }
    for(int i=a;i<c;i++)
    {
        if(s[i]=='#'&&s[i+1]=='#')
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}