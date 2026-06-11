#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define sq(x)           ((x)*(x))

typedef long long ll;

int main()
{
    FastRead

    ll ans=0;
    string s;

    cin>>s;

    ll temp = 0;

    for(ll i=0;i<s.size();i++)
    {
        if(s[i]=='A')
            temp++;
        else if(s.substr(i,2)=="BC")
        {
            ans+=temp;
            i++;
        }
        else
            temp = 0;
    }

    cout<<ans;
}
