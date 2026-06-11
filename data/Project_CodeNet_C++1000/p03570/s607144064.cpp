#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long i,v[200005]={0},n,f=0,ans=0,j,cur=0,mm,m,in;
ml mp;
int main()
{
    io
    string s;
    cin>>s;
    n=s.length();
    mp[0]=0;
    for(i=0;i<n;i++)
    {
        cur^=(1<<(s[i]-'a'));
        if(mp.find(cur)!=mp.end())
        m=mp[cur];
        else m=1e9;
        for(j=0;j<26;++j)
        if(mp.find(cur^(1<<j))!=mp.end())
        m=min(m,mp[cur^(1<<j)]);
        if(mp.find(cur)!=mp.end())
        mp[cur]=min(mp[cur],1+m);
        else mp[cur]=1+m;
    }
    cout<<max(1LL,mp[cur]);
    return 0;
}
