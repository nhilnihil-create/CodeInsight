#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define enter putchar('\n')
#define space putchar(' ')
//#define ivorysi
using namespace std;
typedef long long int64;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
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
int N,A[15];
int64 dp[15][2];
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    read(N);
    for(int i = 1 ; i <= N ; ++i) read(A[i]);
    dp[0][1] = 1;
    for(int i = 1 ; i <= N ; ++i) {
        for(int j = -1 ; j <= 1 ; ++j) {
            if((A[i] + j) & 1) {
                dp[i][1] += dp[i - 1][1];
                dp[i][0] += dp[i - 1][0];
            }
            else {
                dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
            }
        }
    }
    out(dp[N][0]);enter;
}