#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
ll a, b;
int arr[5010];
ll D[5010][5010];

int main() {
    int i, j;

    scanf("%d%lld%lld",&n,&a,&b);
    for (i=1;i<=n;i++) {
        scanf("%d",&arr[i]);
    }
    memset(D,0x3f,sizeof(D));
    D[0][0] = 0;
    for (i=1;i<=n;i++) {
        for (j=0;j<arr[i];j++) {
            D[i][arr[i]] = min(D[i][arr[i]],D[i-1][j]);
            D[i][j] = min(D[i][j],D[i-1][j]+a);
        }
        for (j=arr[i]+1;j<=n;j++) {
            D[i][j] = min(D[i][j],D[i-1][j]+b);
        }
    }
    ll mini = LINF;
    for (i=0;i<=n;i++) mini=min(mini,D[n][i]);
    printf("%lld\n",mini);

    return 0;
}
