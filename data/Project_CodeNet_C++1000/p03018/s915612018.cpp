#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s; cin >> s;
    int n=s.size();
    long long int ans=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A')
        {
            cnt++;
        }
        else if(s[i]=='B' && s[i+1]=='C')
        {
            ans=ans+cnt;
            i++;
        }
        else
        {
            cnt=0;
        }
    }
    cout << ans;
}