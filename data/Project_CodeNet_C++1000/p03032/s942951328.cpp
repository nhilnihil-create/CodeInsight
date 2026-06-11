#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N, K;
    vector<ll> gems;
    ll maxi = 0;
    cin >> N >> K;
    gems.resize(N);
    for(ll i = 0;i < N;i++) cin >> gems[i];
    for(ll a = 0;a <= min(N, K);a++) {
        for(ll b = 0;b <= min(N, K);b++) {
            vector<ll> v;
            ll count = 0;
            if(a + b > min(N, K)) break;
            for(ll i = 0;i < a;i++) v.push_back(gems[i]), count += gems[i];
            for(ll i = 0;i < b;i++) v.push_back(gems[gems.size() - 1 - i]), count += gems[gems.size() - 1 - i];
            sort(v.begin(), v.end());
            for(ll i = 0;i < min((ll)v.size(), K - (a + b));i++) {
                if(v[i] >= 0) break;
                count -= v[i];
            }
            maxi = max(maxi, count);
        }
    }
    cout << maxi << endl;
    return 0;
}
