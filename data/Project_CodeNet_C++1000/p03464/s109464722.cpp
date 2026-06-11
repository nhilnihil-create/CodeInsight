#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

ll K;
vector<ll> A;
bool isOK(ll start, ll goal) {
    for(int i = 0; i < K; i++) {
        start -= start % A[i];
    }
    if(start >= goal)
        return true;
    else
        return false;
}

ll binary_search(int key) {
    ll ng = 1;        //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll ok = longinf;  // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if(isOK(mid, key))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {
    cin >> K;
    A.resize(K);
    for(int i = 0; i < K; i++) cin >> A[i];
    ll small = binary_search(2), large = binary_search(3);
    if(small >= large)
        cout << -1;
    else
        cout << small << " " << large - 1 << "\n";
    return 0;
}