#include <bits/stdc++.h>
#include <cstring>
#include<algorithm>

#define pi 2*acos(0.00)
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define nl '\n'
#define null '\0'
#define mx 1000007
#define bdyptb return 0;

using namespace std;
int main()
{
    fastio;
    string s;
    cin>>s;
    ll i,j,k=0,t=0;
    if(s.size()<3)
    {
        cout<<0<<nl;
        bdyptb;
    }
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='A')
        {
            k++;            
        }
        else if(s[i]=='B'&& s[i+1]=='C'&& i+1<s.size())
                {t+=k;i++;}
            // swap(s[i],s[i+1]);  swap(s[i+1],s[i+2]);           
            
        else k=0;
    }    
    cout<<t<<nl;

    bdyptb;
}