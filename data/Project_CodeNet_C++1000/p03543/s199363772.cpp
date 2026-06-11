#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int32_t main()
{
    string s;
    cin>>s;
    int ans=1;
    for(int i=1;i<s.size();i++)
    {
        if(ans>=3)
        break;
        if(s[i]==s[i-1])
        ans++;
        else
        ans=1;
    }
    if(ans>=3)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    


}