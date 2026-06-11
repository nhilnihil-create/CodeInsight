#include <bits/stdc++.h>
#define enter putchar('\n')
#define space putchar(' ')
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define MAXN 1000005
#define mo 999999137
#define pb push_back
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
        res = res * 10 + c - '0';
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
int N;
int64 M;
int a[100005],num[100005],cnt;
int sum[100005][2],c[200005];
int tr[200005];
int lowbit(int x) {return x & -x;}
void Insert(int x,int v) {
    while(x <= 2 * N + 1) {
        tr[x] += v;
        x += lowbit(x);
    }
}
int Query(int x) {
    int res = 0;
    while(x > 0) {
        res += tr[x];
        x -= lowbit(x);
    }
    return res;
}
bool check(int x) {
    for(int i = 1 ; i <= N ; ++i) {
        sum[i][0] = sum[i - 1][0] + (a[i] <= x);
        sum[i][1] = sum[i - 1][1] + (a[i] > x);
    }
    memset(tr,0,sizeof(tr));
    for(int i = 1 ; i <= N ; ++i) Insert(sum[i][1] - sum[i][0] + N + 1,1);
    int64 res = 0;
    for(int i = 1 ; i <= N ; ++i) {
        int t = sum[i - 1][1] - sum[i - 1][0] + N + 1;
        res += Query(t - 1);
        Insert(sum[i][1] - sum[i][0] + N + 1,-1);
    }
    return res >= M;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    read(N);
    for(int i = 1 ; i <= N ; ++i) {read(a[i]);num[i] = a[i];}
    M = 1LL * N * (N + 1) / 2;
    M = M / 2 + 1;
    sort(num + 1,num + N + 1);
    cnt = unique(num + 1,num + N + 1) - num - 1;
    int L = 1,R = cnt;
    while(L < R) {
        int mid = (L + R) >> 1;
        if(check(num[mid])) R = mid;
        else L = mid + 1;
    }
    out(num[L]);enter;
    return 0;
}