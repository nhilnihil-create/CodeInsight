#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;
    vector< pair<int,int> > sushi(N);
    for(int i=0; i<N; i++) {
        cin >> sushi[i].second >> sushi[i].first;
        sushi[i].second--;
    }

    sort(sushi.rbegin(), sushi.rend());
    int64_t ans = 0, sum = 0, x = 0;
    vector<int> v(N);
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<K; i++) {
        int64_t d = sushi[i].first;
        int t = sushi[i].second;
        sum += d;
        if(v[t]) {
            pq.emplace(d);
        } else {
            v[t] = 1;
            ++x;
        }
    }

    ans = sum + x*x;
    for(int i=K; i<N; i++) {
        if(pq.empty()) break;
        int64_t d = sushi[i].first;
        int t = sushi[i].second;
        if(v[t]) continue;
        v[t] = 1;
        ++x;
        sum += d;
        sum -= pq.top();
        pq.pop();
        ans = max(ans, sum + x*x);
    }

    cout << ans << endl;
    return 0;
}
