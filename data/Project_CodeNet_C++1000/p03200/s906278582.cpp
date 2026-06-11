#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    ll ans=0,c=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='W')
        {
            ans+=i-c;
            c++;
        }
    }
    cout<<ans<<endl;
    return 0;
}