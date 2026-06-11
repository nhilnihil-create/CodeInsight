#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 200005
using namespace std;
using LL = long long;
int n,h[M],a[M];
LL dp[M],tree[M];
int low(int x) {
    return x&-x;
}
LL ask(int x) {
    LL res = 0;
    for (int i=x; i>0; i-=low(i)) res = max(res, tree[i]);
    return res;
}
void upd(int x,LL v) {
    for (int i=x; i<=n; i+=low(i)) tree[i] = max(tree[i], v);
}

int main()
{
    scanf("%d", &n);
    REP(i,1,n) scanf("%d", &h[i]);
    REP(i,1,n) scanf("%d", &a[i]);
    
    REP(i,1,n) {
        dp[i] = ask(h[i]-1) + a[i];
        upd(h[i], dp[i]);
    }
    printf("%lld\n", *max_element(dp+1, dp+n+1));
    return 0;
}
