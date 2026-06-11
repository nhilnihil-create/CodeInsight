#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pII;
#define pb push_back
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof(x))
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int maxn=1e6+5;
//ll fmod(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%mod;y>>=1;x=x*x%mod;}return res;}
//ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
int ans[maxn];
int main()
{
    int n,a,b;
    while(cin>>n>>a>>b)
    {
        int p = sqrt(n);
        //cout<<p<<endl;
        if(a + b > n + 1||a + b < p + n/p + (n%p?1:0))
        {
            //cout<<(a + b > n + 1||a + b < p + n/p + (n%p?1:0))<<endl;
            cout<<-1<<endl;
            continue;
        }
        int x = min(a, b),y = max(a, b);
        if(n/y + (n%y?1:0) > x)
        {
            cout<<-1<<endl;
            continue;
        }
        int now;
        int pos = 2*n;
        int have = 0;
        clr(ans,0);
        int gg = 0;
        int upper = n/y + (n%y?1:0);
        for(int j = 1; j <= upper; ++j)
        {
            now = y*(j - 1);
            int res = 2*n - j*y + 1;
            for(int i = 1; i <= y; i++)
            {
               // cout<<now<<endl;
                ans[res++] = ++now;
                if(i == y)
                    gg++;
                if(j + n - now == x)
                {
                    //cout<<j + n - now<<endl;
                    have = 1;
                    break;
                }
            }
            if(have)break;
        }
        //cout<<now<<endl;
        if(!gg)
        {
            cout<<-1<<endl;
            continue;
        }
        int pp = n - now;
        for(int i = pp; now != n&&i>=1 ;--i)
        {
            //cout<<now<<endl;
            ans[i] = ++now;
        }



        if(a>b)
        {
            int cnt = 0;
            for(int i = 1; i <= 2*n; ++i)
                if(ans[i])
            {
                cnt++;
                //cout<<i<<"pp";
                printf("%d%c",ans[i],cnt == n?'\n':' ');
            }
        }
        else
        {
            int cnt = 0;
            for(int i = 2*n; i >= 1; --i)
                if(ans[i])
            {
                cnt++;
                printf("%d%c",ans[i],cnt == n?'\n':' ');
            }
        }
    }

}














