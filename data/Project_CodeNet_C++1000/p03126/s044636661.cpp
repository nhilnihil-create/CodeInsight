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
    int N, M;
    cin >> N >> M;

    vector<int> A(M, 0);
    for (int i = 0; i < N; i++) {
        int Ki;
        cin >> Ki;
        for (int j = 0; j < Ki; j++) {
            int Aij;
            cin >> Aij;
            A[Aij - 1]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (A[i] == N) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
