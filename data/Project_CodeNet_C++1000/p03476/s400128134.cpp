#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

const int MAX_N = 100007;

vector<bool> is_prime(MAX_N, true);
vector<int> cum_like(MAX_N, 0);

void enum_prime() {
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < MAX_N; i++) {
        if (!is_prime[i]) continue;
        for (int j = 2 * i; j < MAX_N; j += i) is_prime[j] = false;
    }
    return;
}

void make_cum_like() {
    REP2(i, 1, MAX_N) {
        cum_like[i] = cum_like[i-1];
        if (i % 2 == 1 && is_prime[i] && is_prime[(i+1)/2]) cum_like[i]++;
    }
    return;
}

int num_like(int l, int r) {
    int num_like = cum_like[r] - cum_like[l-1];
    return num_like;
}

int main() {
    enum_prime();
    make_cum_like();
    int Q; cin >> Q;
    REP(i, Q) {
        int l, r; cin >> l >> r;
        int ans = num_like(l, r);
        PRINT(ans);
    }
    return 0;
}