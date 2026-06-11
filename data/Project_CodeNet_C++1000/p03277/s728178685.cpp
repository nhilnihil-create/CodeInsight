#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005;

struct BIT{
    int d[2 * N];
    void i(){ fill(d + 1, d + 2 * N, 0); }
    void u(int x){ for(; x < 2 * N; x += x & -x) d[x]++; }
    int g(int x){ int r = 0; for(; x; x &= x - 1) r += d[x]; return r; }
} B;

int n, a[N];
ll t;

int f(int x){
    ll r = 0;
    B.i();
    B.u(N);
    for(int i = 0, j = N; i < n; i++){
        j += (a[i] <= x ? 1 : -1);
        r += B.g(j - 1);
        B.u(j);
    }
    return (r > t / 2);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    t = 1LL * n * (n + 1) / 2;
    int s = *min_element(a, a + n), e = *max_element(a, a + n);
    while(s < e){
        int m = (s + e) / 2;
        if(f(m)) e = m;
        else s = m + 1;
    }
    printf("%d\n", s);
}