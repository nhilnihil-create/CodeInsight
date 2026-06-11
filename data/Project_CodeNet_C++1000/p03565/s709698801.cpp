#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll mod=1e9+7;
int main()
{
    string s,t;
    cin>>s>>t;
    int n=s.length();
    int m=t.length();
    string ans;
    for(int i=n-m;i>=0;i--)
    {
        int flag=0;
        for(int j=0;j<m;j++)
        {
            if(s[i+j]=='?')
            continue;
            if(s[i+j]!=t[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int j=0;j<m;j++)
            {
                s[i+j]=t[j];
            }
            for(int k=0;k<n;k++)
            {
                if(s[k]=='?')
                s[k]='a';
            }
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<"UNRESTORABLE";
}