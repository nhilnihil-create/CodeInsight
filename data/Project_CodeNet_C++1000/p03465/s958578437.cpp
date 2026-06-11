#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=(int)b;++i)
#define per(i,a,b) for(int i=a;i>=(int)b;--i)
#define ll long long

bitset<2000*2000+5>bs;
int main()
{
    IOS
    int n,sum=0;cin>>n; bs[0]=1;
    rep(i,1,n)
    {
        int x;cin>>x;
        sum+=x;
        bs|=bs<<x;
    }
    rep(i,(sum+1)/2,sum)
    {
        if(bs[i])
        {
            cout<<i<<"\n";
            return 0;
        }
    }
}
