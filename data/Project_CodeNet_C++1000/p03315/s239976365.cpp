//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,t,n,j,k,ans=0;
    string s;
    cin>>s;
    for(i=0; s[i]; i++)
        if(s[i]=='-')
            ans--;
        else
            ans++;

    cout<<ans<<endl;

return 0;
}



