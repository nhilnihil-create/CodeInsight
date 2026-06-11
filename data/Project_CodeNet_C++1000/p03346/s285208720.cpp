#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int INF = 1e9;

signed main() {
    int N;
    cin >> N;
    vector<pair<int, int>> A;
    for (int i = 0; i < N; i++) {
        int e; cin >> e;
        A.emplace_back(e, i);
    }
    A.emplace_back(INF, -1);
    
    int cnt = 1;
    int ans = 1;
    sort(A.begin(), A.end());
    for (int i = 1; i <= N; i++) {
        if (A[i-1].second < A[i].second) cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = N-ans;
    cout << ans << endl;
    return 0;
}