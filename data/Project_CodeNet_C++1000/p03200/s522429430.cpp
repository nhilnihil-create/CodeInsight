#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long 
#define F(n) for(int i = 0; i < n; ++i)
#define Debug cout<<endl<<"I AM IRONMAN"<<endl

int main ()
{
    fastio;
    ll ans=0,black=0;
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='B')
        {
            black++;
        }
        else
        {
            ans+=black;
        }
        
    }
    cout << ans;
    return 0;
}