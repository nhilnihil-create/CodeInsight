#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

long double N;
ll A, B, C, D, E;
int main() {
    cin >> N >> A >> B >> C >> D >> E;

    long double min_val = min({A, B, C, D, E});

    printf("%lld\n", (ll)ceil((long double) N / min_val) + 4);
}