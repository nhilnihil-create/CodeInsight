#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<deque>
#include<map>
using namespace std;
typedef long long ll;

int main() {
    long long N, K; cin >> N >> K;
    vector<vector<long long> > s(N);
    for (int i = 0; i < N; ++i) {
        long long t, d; cin >> t >> d; --t;
        s[t].push_back(d);
    }
 
    int inf = 1e9;
    for (auto &v : s) {
        sort(v.begin(), v.end(), greater<long long>());
        if (v.empty()) v.push_back(-inf);
    }
 
    sort(s.begin(), s.end(), [&](vector<long long> a, vector<long long> b) {
            return a[0] > b[0];
        });
 
    long long cur = 0;
    priority_queue<long long> que;
    for (int i = 0; i < K; ++i) {
        cur += s[i][0];
        for (int j = 1; j < s[i].size(); ++j) que.push(s[i][j]);
    }
    for (int i = K; i < N; ++i) for (int j = 0; j < s[i].size(); ++j) que.push(s[i][j]);
 
    long long res = cur + K*K;
    for (long long x = K-1; x >= 1; --x) {
        long long v = s[x][0];
        long long w = que.top();
        if (v < w) {
            que.pop(); cur += w;
            que.push(v); cur -= v;
        }
        res = max(res, cur + x*x);
    }
    cout << res << endl;
}