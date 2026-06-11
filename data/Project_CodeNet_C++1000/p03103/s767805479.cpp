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

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;
const double PI=3.14159265358979323846;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> ab(N);
    for (int i = 0; i < N; i++) {
        cin >> ab[i].first >> ab[i].second;
    }

    sort(ab.begin(), ab.end(), [](const pair<int, int>& left, const pair<int, int>& right) {
        return left.first < right.first;
    });

    long long cost = 0;
    long long lastM = M;
    int index = 0;
    while (lastM > 0) {
        // cout << ab[index].first << ", " << ab[index].second << endl;
        cost += ab[index].first * min(ab[index].second, lastM);
        lastM -= ab[index].second;
        index++;
    }

    cout << cost << endl;

    return 0;
}
