#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 2^i <= x を満たす最大の i
int log_x(int x){
    return 31 - __builtin_clz(x);
}

int main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    multiset<int> se;
    for (int i = 0; i < N; ++i) {
        se.insert(A[i]);
    }
    ll ans = 0;
    while (! se.empty()){
        auto iter = se.end();
        iter--;
        int x = *iter;
        se.erase(iter);
        int i = log_x(x);
        x = pow(2, i+1) - x;
        iter = se.find(x);
        if(iter != se.end()){
            ans++;
            se.erase(iter);
        }
    }
    cout << ans;
    return 0;
}