#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<tuple<int, int, int>> point(2 * N);
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        point[i] = make_tuple(a, b, 0);
    }
    rep(i, N) {
        int c, d;
        cin >> c >> d;
        point[i + N] = make_tuple(c, d, 1);
    }
    
    sort(point.begin(), point.end());
    priority_queue<int> pq;
    int ans = 0;
    rep(i, 2 * N) {
        if (get<2>(point[i]) == 0) {
            pq.push(get<1>(point[i]));
        } else {
            vector<int> S;
            while (!pq.empty()) {
                int y = pq.top();
                pq.pop();
                if (y < get<1>(point[i])) {
                    ++ans;
                    break;
                }
                S.push_back(y);
            }
            for (int y : S) pq.push(y);
        }
    }
    cout << ans << endl;
    return 0;
}
