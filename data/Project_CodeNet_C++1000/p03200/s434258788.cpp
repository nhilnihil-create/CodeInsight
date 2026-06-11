#include<bits/stdc++.h>
#define lld long long int
#define pb push_back
#define in insert
#define mod 1000000007
#define pi 3.14159265358979

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;
    lld len=s.size();

    lld ans=0,c=0;
    for(lld i=0;i<len;i++)
    {
        if(s[i]=='W')
        {
            ans+=(i-c);
            c++;
        }
    }
    cout<<ans<<"\n";
}
