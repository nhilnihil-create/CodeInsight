#include<bits/stdc++.h>
using namespace std;
#define N 4000000 + 5
#define rep(i, l, r) for(int i = l; i <= r; ++i)
int n, x, sum;
bitset <N> dp;
int read(){
    char c; int x = 0, f = 1;
    c = getchar();
    while(c > '9' || c < '0'){ if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int main(){
    n = read();
    dp[0] = 1;
    rep(i, 1, n) x = read(), dp |= (dp << x), sum += x;
    rep(i, (sum + 1) / 2, sum) if(dp[i]){ printf("%d", i); break;}
    return 0;
}