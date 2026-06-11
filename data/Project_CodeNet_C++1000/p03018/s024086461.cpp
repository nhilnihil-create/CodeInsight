#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    string s;
    long long cnt=0,i,a=0,j,k;
    cin>>s;
    if(s.size()<3)
    {
        cout<<0;
        return 0;
    }
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='A')
        {
            a++;
        }
        else if(s[i]=='B' && s[i+1]=='C' && i+1<s.size())
        {
            cnt=cnt+a;
            i++;
        }
        else
        {
            a=0;
        }
    }
    cout<<cnt;
    return 0;
}

