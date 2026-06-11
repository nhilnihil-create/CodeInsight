// Date: 2020-02-25

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
#define FIO ios::sync_with_stdio(false);cin.tie(0)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const LL mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

LL S[N][2];
int a[N], b[N];

int main() {
    mem(S, -0x3f);
    int n; scanf("%d", &n);
    for(int i = 0; i < (1 << n); ++i) scanf("%d", &a[i]), S[i][0] = a[i];
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < (1 << n); ++i) {
            if(!((i >> k) & 1)) {
                int j = (i | (1 << k));
                b[0] = S[i][0], b[1] = S[i][1];
                b[2] = S[j][0], b[3] = S[j][1];
                sort(b, b+4);
                S[j][0] = b[3], S[j][1] = b[2];
            } 
        }
    }
    LL ans = 0;
    for(int i = 1; i < (1 << n); ++i) {
        ans = max(ans, S[i][0] + S[i][1]);
        printf("%lld\n", ans);
    }

    return 0;
}