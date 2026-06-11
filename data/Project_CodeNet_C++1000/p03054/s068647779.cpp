#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 200005
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
int H,W,N;
int sr,sc;
char s[MAXN],t[MAXN];
int suf[MAXN];
bool Process(char a,char b,int dis,int lim) {
    suf[N + 1] = 0;int sum = 0;
    for(int i = N ; i >= 1 ; --i) {
        suf[i] = suf[i + 1];
        if(s[i] == b) {
            suf[i] = min(suf[i],sum - 1);
            --sum;
        }
        if(t[i] == a) {
            if(sum < 0) ++sum;
        }
    }
    int pos = dis;
    for(int i = 1 ; i <= N ; ++i) {
        if(s[i] == a) ++pos;
        if(pos > lim) return false;
        if(t[i] == b) {
            if(pos - 1 + suf[i + 1] >= 1) --pos;
        }
    }
    return true;
}
void Solve() {
    read(H);read(W);read(N);
    read(sr);read(sc);
    scanf("%s",s + 1);scanf("%s",t + 1);
    if(!Process('D','U',sr,H) || !Process('U','D',H + 1 - sr,H) ||
    !Process('R','L',sc,W) || !Process('L','R',W + 1 - sc,W)) {
        puts("NO");
    }
    else puts("YES");
}
int main() {
    Solve();
}