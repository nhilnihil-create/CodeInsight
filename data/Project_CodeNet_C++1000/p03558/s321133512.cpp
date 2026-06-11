#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <bits/stdc++.h>

using ll = long long;

// 処理内容
int main() {

    ll k; scanf("%lld", &k);
    ll dp[100000];
    for (ll i = 0; i < k; i++) dp[i] = 0x7FFFFFFFFFFFFFFFLL;
    dp[1] = 1;

    // deque
    ll qv[100000] = {1};
    ll qc[100000] = {1};
    ll qbeg = 0, qend = 1;

    while (qbeg != qend) {

        ll c = qc[qbeg];
        ll v = qv[qbeg];
        qbeg++; if (qbeg == k) qbeg = 0; // pop_front

        ll n1 = -~v; if (n1 == k) n1 = 0;
        ll n2 = v * 10; while (n2 >= k) n2 -= k;
        ll temp;
        if (dp[n1] > (temp = -~dp[v])) {
            dp[n1] = temp;
            // push_back
            qv[qend] = n1;
            qc[qend] = temp;
            qend++; if (qend == k) qend = 0;
        }
        if (dp[n2] > (temp = dp[v])) {
            dp[n2] = temp;
            // push_front
            qbeg--; if (qbeg == -1) qbeg = ~-k;
            qv[qbeg] = n2;
            qc[qbeg] = temp;
        }
        
    }

    printf("%lld", dp[0]);
    
}