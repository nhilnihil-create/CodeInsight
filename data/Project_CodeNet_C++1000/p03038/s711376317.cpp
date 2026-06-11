#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    priority_queue<int, vector<int>, greater<int>> que;
    int tmp;
    rep(i, N) {
        cin >> tmp;
        que.push(tmp); 
    }

#if 0
    rep(i, N) {
        cout << que.top() << ", ";
        que.pop();
    }
    cout << endl;
#endif

    vector<pair<int, int>> cb(M);
    int B, C;
    rep(i, M) {
        cin >> B >> C;
        cb[i] = {C, B};
    }

    sort(cb.rbegin(), cb.rend());
    rep(i, M) {
        C = cb[i].first;
        B = cb[i].second;
        rep(j, B) {
            int top = que.top();
            if(top < C) {
                que.pop();
                que.push(C);
            } else {
                break;
            }
        }
    }
    uint64_t ret = 0;
    rep(i, N) {
        ret += que.top();
        que.pop();
    }
    cout << ret << endl;

    return 0;
}

