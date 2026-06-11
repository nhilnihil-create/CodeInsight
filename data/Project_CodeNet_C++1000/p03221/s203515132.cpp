#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for(int i=0; i<M; i++) cin >> A[i] >> B[i], A[i]--;

    vector<vector<int>> vals(N);
    for(int i=0; i<M; i++) vals[A[i]].push_back(B[i]);

    for(int i=0; i<N; i++)
    {
        sort(vals[i].begin(), vals[i].end());
        vals[i].erase(unique(vals[i].begin(), vals[i].end()), vals[i].end());
    }

    for(int i=0; i<M; i++)
    {
        printf("%06d", A[i]+1);
        int id = lower_bound(vals[A[i]].begin(), vals[A[i]].end(), B[i]) - vals[A[i]].begin();
        printf("%06d\n", id + 1);
    }


    return 0;
}
