#include <bits/stdc++.h>

using namespace std;

int nadjiX(string s,int n)
{
    for(int i=n/2;i<n-1;i++)
        if(s[i]!=s[i+1])return i;
    return -1;
}

int nadjiY(string s,int n)
{
    for(int i=n/2;i>0;i--)
        if(s[i]!=s[i-1])return i;
    return -1;
}
vector<int>res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    int n=s.size();
    for(int i=1;i<s.size();i++)
    {
        if(s[i]!=s[i-1])res.push_back(max(i,n-i));
    }
    if(res.size()>0)cout<<*min_element(res.begin(),res.end());
    else cout<<n;
    /*int n=s.size();
    int i=s.size()/2;
    int x=i;
    int y=i;
    bool xx=false;
    bool yy=false;
    while(x>=0&&y<=n)
    {
        if(s[x]!=s[x-1]){xx=true;break;}
        if(s[y]!=s[y+1]){yy=true;break;}
        x--;
        y++;
    }
    if(xx=true)
    {
        cout<<max(x,(n-x));
        return 0;
    }
    if(yy=true)cout<<max(y,n-y);*/

    return 0;
}

