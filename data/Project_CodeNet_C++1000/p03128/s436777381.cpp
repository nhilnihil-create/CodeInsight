#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

template<class T> void chmax(T &a, T b) { a = max(a, b); }
const int cost[] = {0,2,5,5,4,5,6,3,7,6};

int main() {
    lint N, M;
    cin >> N >> M;

    vector<lint> A(M);
    for(auto& elem : A)  cin >> elem;
    sort(A.rbegin(), A.rend());

    vector<lint> dp(N+1, -1e18);
    dp[0] = 0;
    for(auto a : A)
    for(int m=0; m<N; m++) {
        if(m+cost[a]<=N) chmax(dp[m+cost[a]], dp[m]+1);
    }

    auto check = [&](int a, int c) {
        if(N-cost[a]*c < 0) return false;
        bool c1 = (dp[N-cost[a]*c] == dp[N]-c);
        return c1;
    };

    for(auto a : A) {
        int ok = 0;
        int ng = N+1;
        while(ng-ok > 1) {
            int mid = (ok+ng)/2;
            (check(a,mid) ? ok : ng) = mid;
        }
        N -= cost[a]*ok;
        for(int k=0; k<ok; k++) cout << a;
    }
    cout << endl;
}