#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define inf 1e18
#define pi acos(-1.0)
#define mod 998244353

int main(void)
{
    fastio;

    string s;
    cin >> s;
    int o=0,e=0,l=s.size(),i,m;
    for(i=0;i<l;i++)
    {
        if(i%2)
        {
            if(s[i]=='0')e++;
        }
        else
        {
            if(s[i]=='0')o++;
        }
    }
    //cout << o << " " << e << " ";
    if(l%2){m=l/2;l=l/2+1;}
    else {m=l/2;l=l/2;}

    cout << min(l-o+e,o+m-e);

    return 0;
}
