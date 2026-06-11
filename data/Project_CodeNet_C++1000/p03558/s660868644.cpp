#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <cstdio>
#include <cstring>

#define ll long long

// 処理内容
int main() {

    ll k; scanf("%lld", &k);
    ll dp[100000];
    memset(dp, 0x7F, sizeof(unsigned ll) * k);
    dp[1] = 1;

    // deque
    ll qv[100000] = {1};
    ll qbeg = 0, qend = 1;

    while (qbeg != qend) {

        ll v = qv[qbeg];
        ll c = dp[v];
        qbeg++; if (qbeg == k) qbeg = 0; // pop_front

        ll n1 = -~v; if (n1 == k) n1 = 0;
        ll n2 = v * 10; while (n2 >= k) n2 -= k;
        if (dp[n1] > -~c) {
            dp[n1] = -~c;
            // push_back
            qv[qend] = n1;
            qend++; if (qend == k) qend = 0;
        }
        if (dp[n2] > c) {
            dp[n2] = c;
            // push_front
            qbeg--; if (qbeg == -1) qbeg = ~-k;
            qv[qbeg] = n2;
        }
        
    }

    printf("%llu", dp[0]);
    
}