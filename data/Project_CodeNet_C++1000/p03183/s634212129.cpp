#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int MN = 1e3+2, MS = 2e4+2;
struct block {
    int w,s,v;
} blocks[MN];
ll dp[MS];
int main() {
    int n; ll ret = 0;
    scanf ("%d",&n);
    for (int i = 0; i < n; i++) scanf ("%d%d%d",&blocks[i].w,&blocks[i].s,&blocks[i].v);
    sort(blocks,blocks+n,[](block a, block b) {return a.w + a.s < b.w + b.s;});
    for (int i = 0; i < n; i++) for (int j = blocks[i].s; j >= 0; j--) dp[j+blocks[i].w] = max(dp[j+blocks[i].w],dp[j]+blocks[i].v);
    for (int i = 0; i < MS; i++ ) ret = max(ret,dp[i]);
    printf ("%lld\n",ret);
    return 0;
}