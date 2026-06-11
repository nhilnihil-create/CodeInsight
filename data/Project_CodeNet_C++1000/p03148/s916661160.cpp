#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<array<ll, 2>> td(N);
    for(int i=0;i<N;i++){
        cin >> td[i][1] >> td[i][0];
    }
    sort(td.begin(), td.end(), greater<array<ll, 2>>());

    ll res = 0;
    ll vsum = 0;
    set<ll> kind;
    stack<ll> unused;
    for(int i=0; i<K; i++){
        auto t = td[i][1];
        auto d = td[i][0];
        vsum += d;;
        if(kind.count(t) > 0) unused.push(d);
        else kind.insert(t);
    }
    res = vsum + kind.size() * kind.size();
    for(int i=K; i<N; i++){
        auto t = td[i][1];
        auto d = td[i][0];
        if(kind.count(t) > 0) continue;
        kind.insert(t);
        vsum += d;
        if(unused.size()==0) break;
        vsum -= unused.top(); unused.pop();
        res = max(res, (ll)(vsum + kind.size() * kind.size()));
    }
    cout << res << endl;

    return 0;
}