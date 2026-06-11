#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 5005
//#define ivorysi
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        res = res * 10 +c - '0';
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
int64 A,B;
int64 dp[MAXN][2 * MAXN],s[MAXN][2 * MAXN];
int p[MAXN],pos[MAXN];
void Solve() {
    read(N);read(A);read(B);
    for(int i = 1 ; i <= N ; ++i) {read(p[i]);pos[p[i]] = i;}
    for(int i = 1 ; i <= N ; ++i) {
        s[i][0] = 1e18;
        for(int j = 1 ; j <= 2 * N + 1 ; ++j) {
            if(j & 1) {
                dp[i][j] = s[i - 1][j] + (j < pos[i] * 2 ? B : A);
            }
            else {
                dp[i][j] = s[i - 1][j - 1] + (j != pos[i] * 2 ? (j < pos[i] * 2 ? B : A): 0);
            }
            s[i][j] = min(s[i][j - 1],dp[i][j]);
        }
    }
    out(s[N][2 * N + 1]);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
