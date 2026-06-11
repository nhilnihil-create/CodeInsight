#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    for (int i = 0; i < M; i++)
    {
        cin >> X[i];
    }

    if (M <= N)
    {
        cout << "0" << endl;
        return;
    }
    
    int ans;
    ans = 0;
    sort(X.begin(), X.end());
    vector<int> interval(M-1);
    for (int i = 0; i < M-1; i++)
    {
        interval[i] = X[i+1] - X[i];
        ans += interval[i];
    }
    sort(interval.begin(), interval.end(), greater<>());
    for (int i = 0; i < N-1; i++)
    {
        ans -= interval[i];
    }
    
    cout << ans << endl;
    
}

int main() {
    solve();
    return 0;
}