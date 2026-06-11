#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int N=1000000+5;

int n;
string s;
int q;

ll D;
ll DM;
ll cnt_M;

inline void add(int p)
{
    if(s[p]=='D') D++;
    if(s[p]=='M')
    {
        DM+=D;
        cnt_M++;
    }
}

inline void del(int p)
{
    if(s[p]=='D')
    {
        D--;
        DM-=cnt_M;
    }
    if(s[p]=='M')
    {
        cnt_M--;
    }
}

inline ll slove(ll l)
{
    ll ans=0LL;
    D=0LL;
    DM=0LL;
    cnt_M=0LL;

    for(int i=1;i<=n;i++)
    {
        add(i);
        if(i>l)
        {
            del(i-l);
        }
        if(s[i]=='C')
        {
            ans+=DM;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    s="."+s;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int l;
        cin>>l;
        cout<<slove(l)<<"\n";
    }
    return 0;
}
