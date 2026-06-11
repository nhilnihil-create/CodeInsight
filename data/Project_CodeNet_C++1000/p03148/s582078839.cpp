#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>
#include<fstream>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

const ll inf = 1LL << 40;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string filename = "result.txt";
    ofstream writing_file;
    writing_file.open(filename, ios::out);

    ll N, K;
    cin >> N >> K;
    vector<multiset<ll>> sushi(N, multiset<ll>());
    Rep (i, N) {
        ll t, d;
        cin >> t >> d;
        t--;
        sushi[t].insert(-d);
    }

    Rep (i, N) {
        if (sushi[i].empty()) sushi[i].insert(inf);
    }

    // Rep (i, N) {
    //     cout << -*sushi[i].begin() << endl;
    // }

    sort(sushi.begin(), sushi.end(), [&](multiset<ll> a, multiset<ll> b) {
        return -*a.begin() > -*b.begin();
    });

    Rep (i, N) {
        writing_file << -*sushi[i].begin() << endl;
    }

    ll cur = 0;
    priority_queue<ll> q;
    Rep (i, K) {
        auto itr = sushi[i].begin();
        cur += -*itr;
        itr++;
        while (itr != sushi[i].end()) {
            q.push(-*itr);
            itr++;
        }
    }

    for (ll i = K; i < N; i++) {
        for (ll e : sushi[i]) {
            q.push(-e);
        }
    }

    ll res = cur + K*K;
    writing_file << K << " " << cur + K*K << "\n";
    for (ll x = K-1; x >= 1; x--) {
        ll v = -*sushi[x].begin();
        ll w = q.top();
        if (v < w) {
            q.pop();
            cur += w;
            q.push(v);
            cur -= v;
        }
        writing_file << x << " " << cur + x*x << "\n";
        res = max(res, cur + x*x);
    }
    
    cout << res << endl;
}