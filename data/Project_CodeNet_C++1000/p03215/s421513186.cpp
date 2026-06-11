#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, k; cin >> n >> k;
    vector<ll> sum(n + 1);
    for(int i = 0; i < n; i++) {
        int a; cin >> a; sum[i + 1] = sum[i] + a;
    }
    vector<ll> a;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= n; j++)a.push_back(sum[j] - sum[i]);
    }

    ll res = 0;

    for(int i = 60; i >= 0; i--) {
        vector<ll> nxt;
        for(auto j : a) {
            if(j & (1LL << i))nxt.push_back(j);
        }
        if((int)nxt.size() >= k) {
            res |= (1LL<<i);
            a = nxt;
        }
    }
    cout << res << endl;
}