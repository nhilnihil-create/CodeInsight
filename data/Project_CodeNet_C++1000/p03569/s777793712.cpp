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
char s[100005];
int N;
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    scanf("%s",s + 1);
    N = strlen(s + 1);
    int p = 1,q = N;
    int ans = 0;
    while(p < q) {
        if(s[p] == s[q]) {++p;--q;}
        else {
            if(s[p] == 'x') {++p;++ans;}
            else if(s[q] == 'x') {--q;++ans;}
            else {puts("-1");return 0;}
        }
    }
    out(ans);enter;return 0;
}