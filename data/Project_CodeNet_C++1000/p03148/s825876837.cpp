#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#define rt return
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repd(i,x,n) for(int i=x;i<=n;i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define gbtb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MSC0(X) memset((X), '\0', sizeof((X)))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define eps 1e-6
#define gg(x) getInt(&x)
#define db(x) cout<<"== [ "<<x<<" ] =="<<endl;
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll powmod(ll a,ll b,ll MOD){ll ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
inline void getInt(int* p);
const int maxn=1000010;
const int inf=0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
int n,k;
struct info
{
    int x,v;
}a[maxn];
bool cmp(info one,info two)
{
    return one.v>two.v;
}
int vis[maxn];
stack<int> s;
int main()
{
    scanf("%d %d",&n,&k);
    repd(i,1,n)
    {
        scanf("%d %d",&a[i].x,&a[i].v);
    }
    sort(a+1,a+1+n,cmp);
    ll cnt=0;
    ll tp=0;
    ll res=0;
    ll ans=0ll;
    repd(i,1,n)
    {
        if(cnt<k)
        {
                if(vis[a[i].x]==0)
                {
                    vis[a[i].x]=1;
                    tp++;
                }else
                {
                    s.push(a[i].v);
                }
                res+=a[i].v;
                cnt++;
                ans=max(ans,res+1ll*tp*tp);
        }
        else{
            if(s.empty())
                break;
            if(vis[a[i].x])
                continue;
            vis[a[i].x]=1;
            tp++;
            res-=s.top();
            res+=a[i].v;
            s.pop();
            ans=max(ans,res+tp*tp);
        }
    }
    printf("%lld\n",ans);
    return 0;
}

inline void getInt(int* p) {
    char ch;
    do {
        ch = getchar();
    } while (ch == ' ' || ch == '\n');
    if (ch == '-') {
        *p = -(getchar() - '0');
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 10 - ch + '0';
        }
    }
    else {
        *p = ch - '0';
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 10 + ch - '0';
        }
    }
}