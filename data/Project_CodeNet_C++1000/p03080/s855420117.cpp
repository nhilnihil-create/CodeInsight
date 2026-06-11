#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int r=0;
    int b=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R')
        {
            r++;
        }else
        {
            b++;
        }
    }
    if(b>=r)
    {
        cout<<"No"<<endl;
    }else
    {
        cout<<"Yes"<<endl;
    }
}
