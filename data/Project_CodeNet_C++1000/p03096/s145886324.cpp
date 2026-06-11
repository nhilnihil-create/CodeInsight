#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define MOD 1000000007

int N;
vector<int> C;
vector<int> memo;
vector<int> nearest;
vector<int> ind;

int f(int i) {
    if (i >= nearest.size()) return 1;
    if (memo[i] != -1) return memo[i];
    if (nearest[i] == -1) {
        return memo[i] = f(i+1) % MOD;
    } else {
        return memo[i] = (f(nearest[i]) + f(i+1)) % MOD;
    }
}

int main()
{
    cin >> N;
    C.resize(N); for (auto& e : C) cin >> e;
    C.erase(unique(C.begin(), C.end()), C.end());

    ind.assign(200000+1, -1);
    nearest.assign(C.size(), -1);
    for (int i = C.size()-1; i >= 0; i--) {
        if (ind[C[i]] != -1) nearest[i] = ind[C[i]];
        ind[C[i]] = i;
    }

    memo.assign(C.size(), -1);
    ll ans = f(0);
    cout << ans << endl;
}
