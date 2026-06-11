#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    string s;
    long long i,cnt1=0,cnt2=0;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(i%2==0)
        {
            if(s[i]!='0')
            {
                cnt1++;
            }
        }
        else
        {
            if(s[i]!='1')
            {
                cnt1++;
            }
        }
    }
    for(i=0;i<s.size();i++)
    {
        if(i%2==0)
        {
            if(s[i]!='1')
            {
                cnt2++;
            }
        }
        else
        {
            if(s[i]!='0')
            {
                cnt2++;
            }
        }
    }
    cout<<min(cnt1,cnt2);
    return 0;
}