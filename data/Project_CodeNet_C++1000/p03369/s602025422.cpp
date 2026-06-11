#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    fast_io
    ll i,j,cnt=0;
    string s;
    cin>>s;
        for(i=0; s[i]; i++)
        {
            if(s[i]=='o') cnt++;
            }
        cout<<700+cnt*100<<endl;

    return 0;
}



