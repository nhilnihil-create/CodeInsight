#include <bits/stdc++.h>
#define enter putchar('\n')
#define space putchar(' ')
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eps 1e-8
//#define ivorysi
using namespace std;
typedef long long int64;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        res = res * 10 - '0' + c;
        c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) out(x / 10);
    putchar('0' + x % 10);
}
int L,N;
void add(int u,int v,int c) {
    out(u);space;out(v);space;out(c);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    read(L);
    int r;
    for(r = 20 ; r >= 0 ; --r) {
        if(L & (1 << r)) break;
    }
    N = r + 1;out(N);space;int M = r * 2 + __builtin_popcount(L) - 1;out(M);enter;
    for(int i = 1 ; i <= N - 1 ; ++i) {
        add(i,i + 1,(1 << i - 1));add(i,i + 1,0);
    }
    for(int i = 1 ; i <= N - 1 ; ++i) {
        if(L & (1 << i - 1)) {
            L ^= (1 << i - 1);
            add(i,N,L);
        }
    }
}