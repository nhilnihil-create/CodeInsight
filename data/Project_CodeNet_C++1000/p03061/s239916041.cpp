#include "bits/stdc++.h"

using namespace std;

long long dp(long long curr, bool alreadySkipped, const vector<long long>& V, vector<vector<long long>>& memo) {
    if (memo[curr][alreadySkipped ? 1 : 0] >= 0) {
        return memo[curr][alreadySkipped ? 1 : 0];
    }
    long long ret = 0;
    if (alreadySkipped) {
        if (curr == V.size() - 2) {
            ret = __gcd(V[curr], V[curr + 1]);
        }
        else {
            ret = __gcd(V[curr], dp(curr + 1, alreadySkipped, V, memo));
        }
    }
    else {
        if (curr == V.size() - 2) {
            long long skip1 = V[curr];
            long long skip2 = V[curr + 1];
            long long take = __gcd(V[curr], V[curr + 1]);
            ret = max(max(skip1, skip2), take);
        }
        else {
            long long skip = dp(curr + 1, true, V, memo);
            long long take = __gcd(V[curr], dp(curr + 1, false, V, memo));
            ret = max(skip, take);
        }
    }
    memo[curr][alreadySkipped ? 1 : 0] = ret;
    return ret;
}

long long gcd(const vector<long long>& V) {
    long long ret = V[0];
    for (long long i = 1; i < V.size(); ++i) {
        ret = __gcd(ret, V[i]);
    }
    return ret;
}

void Main() {
    long long N;
    cin >> N;
    vector<long long> V(N, 0);
    for (long long i = 0; i < N; ++i) {
        cin >> V[i];
    }

    vector<vector<long long>> memo(V.size() + 10, vector<long long>(2, -1));
    long long ans = dp(0, false, V, memo);
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
