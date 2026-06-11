#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    string s;
    cin>>s;

    bool canA = true;
    for(int i=a-1;i<c-1;i++)
    {
        if( s[i] =='#' && s[i+1] == '#')
            canA = false;
    }
    bool canB = true;
    for(int i=b-1;i<d-1;i++)
    {
        if( s[i] =='#' && s[i+1] == '#')
            canB = false;
    }
    if( !(canB && canA)  )
    {
        cout<<"No";
        return 0;
    }
    if( c== d )
    {
        cout<<"No";
        return 0;
    }
    if( c < d )
    {
        cout<<"Yes";
    } else
    {
        bool ans = false;
        for(int i=b-2;i<d-1 ;i++)
        {
            if( s[i] =='.' && s[i+1] =='.' &&  s[i+2] =='.' ) {
                ans = true;
                break;
            }
        }
        if( ans)
            cout<<"Yes";
        else cout<<"No";
    }
}