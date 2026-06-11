#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int n, k, t, d;
    cin >> n >> k;
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++) {
        cin >> t >> d;
        pq.push({d, t});
    }
    unordered_map<int, int> cnt;
    multiset<pair<int, int>> kind;
    priority_queue<pair<int, int>> mx;
    while (!pq.empty()) { // select top different types
        tie(d, t) = pq.top(); pq.pop();
        if (cnt.size() < k && cnt.count(t) == 0) {
            kind.insert({d, t});
            cnt[t] = 1;
        } else {
            mx.push({d, t});
        }
    }
    while(kind.size() < k) {
        if (!mx.empty()) {
            tie(d, t) = mx.top(); mx.pop();
            kind.insert({d, t});
            cnt[t] += 1;
        }
    }
    ll acc = 0, ans = 0;
    for(auto& p: kind)
        acc += p.first;
    ans = acc + cnt.size() * cnt.size();
    while (!mx.empty()) {
        tie(d, t) = mx.top(); mx.pop();
        auto it = kind.begin();
        if (d < it->first)
            break;
        if (--cnt[it->second] == 0)
            cnt.erase(it->second);
        acc -= it->first;
        kind.erase(it);
        acc += d;
        cnt[t] += 1;
        kind.insert({d, t});
        ans = max(ans, acc + (ll)cnt.size()*(ll)cnt.size());
    }
    cout << ans << endl;
    return 0;
}


