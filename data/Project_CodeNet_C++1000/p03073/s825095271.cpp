// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>  
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vl vector<ll>
#define N 100005
#define mod 1000000007


int main()
{   
    string s;cin>>s;
    ll n=s.size();
    ll cnt=0;
    for(ll i=1;i<n-1;i++)
    {
        if(s[i]==s[i-1] && s[i]==s[i+1])
        {
            if(s[i]=='0')
            s[i]='1';
            else
            s[i]='0';
            cnt+=1;
        }
        else if(s[i]==s[i-1] && s[i]!=s[i+1])
        {
            if(s[i]=='1')
            s[i]='0';
            else
            s[i]='1';
            cnt+=1;
        }
    }
    for(ll i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        cnt+=1;
    }
    cout<<cnt<<"\n";
    return 0;
}