#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;

int main() {
    lint n, k;
    cin >> n >> k;

    vector<P> dt(n);
    for(int i=0; i<n; i++) cin >> dt[i].second >> dt[i].first;
    sort(dt.rbegin(), dt.rend());

    lint sum = 0;
    map<lint, lint> inside, all;
    priority_queue<P, vector<P>, greater<P>> pq;
    for(int i=0; i<n; i++) {
        lint d = dt[i].first, t = dt[i].second;
        if(i<k) {
            sum += d;
            pq.push(dt[i]);
            inside[t]++;
        }
        all[t]++;
    }
    lint kind = inside.size();
    lint ans = sum + kind * kind;
    
    for(int i=k; i<n; i++) {
        // 1. 取り除く
        while(!pq.empty()) {
            lint d, t;
            tie(d, t) = pq.top(); pq.pop();
            if(inside[t] == 1) continue;
            inside[t]--;
            sum -= d;
            break;
        }
        if(pq.empty()) break;

        // 2. 追加する
        lint d = dt[i].first, t = dt[i].second;
        pq.push(dt[i]);
        inside[t]++;
        sum += d;
        kind = inside.size();

        ans = max(ans, sum + kind * kind);
    }
    cout << ans << endl;
}