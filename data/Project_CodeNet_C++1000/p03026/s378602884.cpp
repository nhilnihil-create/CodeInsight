#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> G;
vector<int> C;

void dfs(vector<int> &nums, int u, int &cnt) {
    nums[u] = C[cnt++];

    for (int v : G[u]) {
        if (nums[v] != 0) continue;
        dfs(nums, v, cnt);
    }
}


int main() {
    cin >> N;
    G.resize(N); C.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < N; i++) cin >> C[i];

    sort(C.begin(), C.end(), greater<int>());
    int res = 0;
    for (int i = 1; i < N; i++) res += C[i];

    vector<int> nums(N, 0);
    int cnt = 0;
    dfs(nums, 0, cnt);

    cout << res << endl;
    for (int i = 0; i < N; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

