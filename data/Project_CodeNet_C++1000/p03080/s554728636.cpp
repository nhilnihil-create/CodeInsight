#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int r=0;
    int b=0;
    for(int i=0;s[i]!=0;i++)
    {
        if(s[i]=='R')
            r++;
        else
            b++;
    }
    if(r>b)
        cout<<"Yes"<<'\n';
    else
        cout<<"No"<<'\n';
}
