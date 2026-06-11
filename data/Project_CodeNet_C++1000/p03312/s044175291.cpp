#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
//#define ivorysi
#define MAXN 200005
typedef long long int64;
using namespace std;
template<class T>
void read(T &res) {
    res = 0;char c = getchar();T f = 1;
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        res = res * 10 + c - '0';
        c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
        out(x / 10);
    }
    putchar('0' + x % 10);
}
int N;
int64 a[MAXN],sum[MAXN];
int64 get_abs(int l1,int r1,int l2,int r2) {
    return abs((sum[r1] - sum[l1 - 1]) - (sum[r2] - sum[l2 - 1]));
}
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) {
        read(a[i]);sum[i] = sum[i - 1] + a[i];
    }
    int l = 1,p = 2,r = p + 1;
    int64 ans = sum[N];
    while(p <= N - 2) {
        while(l + 1 < p && get_abs(1,l,l + 1,p) > get_abs(1,l + 1,l + 2,p)) ++l;
        r = max(r,p + 1);
        while(r + 1 < N && get_abs(p + 1,r,r + 1,N) > get_abs(p + 1,r + 1,r + 2,N)) ++r;
        int64 m[] = {sum[l],sum[p] - sum[l],sum[r] - sum[p],sum[N] - sum[r]};
        int64 tmp = 0;
        for(int i = 0 ; i <= 3 ; ++i) {
            for(int j = i + 1 ; j <= 3 ; ++j) {
                tmp = max(tmp,abs(m[j] - m[i]));
            }
        }
        ans = min(ans,tmp);
        ++p;
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}