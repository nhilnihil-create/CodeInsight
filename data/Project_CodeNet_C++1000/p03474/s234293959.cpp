#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    fast_io
    ll a,b,i,j;
    string s;
    bool ok;
    cin>>a>>b>>s;
    if(s[a]!='-')
        ok=0;
    else
        ok=1;
    if(ok)
        for(i=0; s[i]; i++)
        {

            if(i!=a)
                if(s[i]>='0'&&s[i]<='9')
                {
                    ok=1;
                }
                else
                {
                    ok=0;
                    break;
                }
        }
    if(ok)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}



