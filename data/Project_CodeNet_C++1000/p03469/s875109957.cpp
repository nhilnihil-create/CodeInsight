#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    string s; cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(i==3) cout<<8;
        else cout<<s[i];
    }
}