#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<vector<int>> sushis;
vector<vector<int>> as;

int main(void) {
    int N, K;
    cin >> N >> K;

    sushis.resize(N);
    for (int i = 0; i < N; i++) {
        int t, d;
        cin >> t >> d;
        t--;
        sushis[t].push_back(d);
    }

    priority_queue<int> q;
    vector<int> bs;

    for (int i = 0; i < N; i++) {
        sort(sushis[i].begin(), sushis[i].end());
        reverse(sushis[i].begin(), sushis[i].end());

        if ((int) sushis[i].size() > 0) {
            bs.push_back(sushis[i][0]);
        }

        for (int j = 1; j < (int) sushis[i].size(); j++) {
            q.push(sushis[i][j]);
        }
    }

    sort(bs.begin(), bs.end());
    reverse(bs.begin(), bs.end());

    ll delicious = 0;
    ll kind = 0;
    ll cand = 0;
    for (int i = 0; i < min((int) bs.size(), K); i++) {
        delicious += bs[i];
        kind++;
    }

    for (int i = kind; i < (int) bs.size(); i++) {
        q.push(bs[i]);
    }

    for (int i = kind; i < K; i++) {
        auto v = q.top();
        q.pop();
        delicious += v;
    }

    cand = delicious + kind * kind;
    // printf("delicious: %lld, kind: %lld, cand: %lld\n", delicious, kind, cand);

    while (kind > 0) {
        auto remove = bs[kind - 1];
        delicious -= remove;
        q.push(remove);
        auto v = q.top();
        q.pop();
        delicious += v;

        kind--;
        chmax(cand, delicious + kind * kind);
        // printf("delicious: %lld, kind: %lld, cand: %lld\n", delicious, kind, cand);
    }

    cout << cand << endl;

    return 0;
}
