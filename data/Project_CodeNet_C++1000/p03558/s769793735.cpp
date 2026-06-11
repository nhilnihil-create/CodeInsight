#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define mst(a,b) memset(a,b,sizeof(a))
#define ALL(x) x.begin(),x.end()
#define pii pair<int, int>
#define debug(a) cout << #a": " << a << endl;
#define eularMod(a, b) a < b ? a : a % b + b
inline int lowbit(int x){ return x & -x; }
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1e5 + 10;
const int mod = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double eps = 1e-6;

int k;
int dis[N];
bool inq[N];

int cal(int x) {
    int res = 0;

    for (; x; x /= 10)
        res += x % 10;

    return res;
}

queue<int> Q;

void spfa() {
    mst(dis, 0x3f);

    dis[1] = 1;
    inq[1] = true;

    Q.push(1);

    for (;!Q.empty();) {
        int u = Q.front();
        Q.pop();

        inq[u] = false;

        int v = (u + 1) % k;

        if (dis[v] > dis[u] + 1) {
            dis[v] = dis[u] + 1;

            if (!inq[v])
                Q.push(v);
        }

        v = (u * 10) % k;

        if (dis[v] > dis[u]) {
            dis[v] = dis[u];

            if (!inq[v])
                Q.push(v);
        }
    }
}

int main() {
#ifdef purple_bro
    freopen("in.txt", "r", stdin);
//    freopen("out.txt","w",stdout);
#endif
    scanf("%d", &k);

    spfa();

    printf("%d\n", dis[0]);
    return 0;
}