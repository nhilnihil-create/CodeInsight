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
    char t[len],u[len];

    for(lld i=0;i<len;i++)
    {
        if(i%2==0){t[i]='0';u[i]='1';}
        else {t[i]='1';u[i]='0';}
    }

    lld c=0,c1=0;
    for(lld i=0;i<len;i++)
    {
        if(s[i]!=t[i])c++;
        if(s[i]!=u[i])c1++;
    }

    cout<<min(c,c1)<<"\n";
}
