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
#define gg(x) getInt(&x)
using namespace std;
typedef long long ll;
inline void getInt(int* p);
const int maxn=1000010;
const int inf=0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
ll n;
ll dp[maxn];
ll a[maxn];
ll k;
int main()
{
    gbtb;
    cin>>n>>k;
    repd(i,1,n)
    {
        cin>>a[i];
    }
    dp[1]=0;
    dp[0]=0;
    repd(i,2,n)
    {
        dp[i]=inf;
    }
    repd(i,2,n)
    {
        for(int j=i-1;j>=max(1ll,i-k);j--)
        {
            dp[i]=min(dp[i],dp[j]+abs(a[i]-a[j]));
        }
    }
    cout<<dp[n];
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