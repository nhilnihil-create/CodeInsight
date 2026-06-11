#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> P(M), Y(M);
    vector<vector<int>> yd(N+1, vector<int>(0));
    for (int i = 0; i < M; i++)
    {
        cin >> P[i] >> Y[i];
        yd[P[i]].push_back(Y[i]);
    }
    for (int i = 0; i < N; i++)
    {
        sort(yd[i+1].begin(), yd[i+1].end());
    }
    for (int i = 0; i < M; i++)
    {
        cout << setfill('0') << setw(6) << P[i] << setfill('0') << setw(6) << (int)(lower_bound(yd[P[i]].begin(), yd[P[i]].end(), Y[i])-yd[P[i]].begin()) + 1 << endl;
    }
    
    

    
}

int main() {
    solve();
    return 0;
}