#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,sum=0;
    cin>>n;
    string s= to_string(n); 
    for(int i=0;i<s.length();i++)
    {
        sum+=s[i]-'0';
    }
    if(n%sum==0)
    {
        cout<<"Yes"<<"\n";
    }
    else
    {
        cout<<"No"<<"\n";
    }
    return 0;
}