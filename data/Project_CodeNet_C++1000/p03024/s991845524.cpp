#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[16];
    cin>>s;
    int l=strlen(s),ans=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='o')
        {
            ans++;
        }
    }
    if((ans+(15-l))>=8)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
