#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,i,j,ans=0;
    string s;
    cin>>s;
    for(i=0; i<s.length()-1; i++)
    {
        if(s[i]==s[i+1])
        {
            ans++;
            if(s[i]=='0')
                s[i+1]='1';
            else
                s[i+1]='0';
        }

    }
    cout<<ans<<endl;



    return 0;
}


