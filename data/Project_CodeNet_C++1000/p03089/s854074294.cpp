#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <list>

using namespace std;
using ll = long long;

const int INF = 1e9;
const long long LINF = 1e18;
const double PI=3.14159265358979323846;

typedef priority_queue<int, vector<int>, greater<int>> priority_queue_asc;

int main() {
    int N;
    cin >> N;

    list<int> b;
    for (int i = 0; i < N; i++) {
        int bi;
        cin >> bi;
        b.push_back(bi);
    }

    list<int> ans;

    for (int i = 0; i < N; i++) {
        list<int>::reverse_iterator itr = b.rbegin();
        for (int j = b.size(); itr != b.rend(); --j, ++itr) {
            // cout << "* " << (*itr) << endl;
            if (*itr == j) {
                break;
            }
        }
        // cout << "---" << endl;

        if (itr == b.rend()) {
            cout << -1 << endl;
            return 0;
        }

        int bj = *itr;
        b.erase((++itr).base());
        // cout << ": " << bj << endl;
        ans.push_front(bj);
    }

    for (const auto& e : ans) {
        cout << e << endl;
    }

    return 0;
}
