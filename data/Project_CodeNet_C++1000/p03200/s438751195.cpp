#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    long long i, cnt=0, ans=0;
    cin>>s;
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='B')
            cnt++;
        else
            ans+=cnt;
    }
    cout<<ans;
}
