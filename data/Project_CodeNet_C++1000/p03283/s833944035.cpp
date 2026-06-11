#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N, M, Q;
    cin >> N >> M;
    cin >> Q;

    vector<int> L(M), R(M);

    vector<int> p(Q), q(Q);

    for (int i = 0; i < M; i++)
    {
        int l, r;
        cin >>l >> r;
        L[i] = l;
        R[i]= r;
    }
    
    for (int i = 0; i < Q; i++)
    {
        int pin, qin;
        cin >> pin >> qin;
        p[i] = pin;
        q[i] = qin;
    }

    vector<vector<int>> trains(N+1, vector<int>(N+1,0));

    for (int i = 0; i < M; i++)
    {
        trains[L[i]][R[i]]++;
    }

    vector<vector<int>> C(N+1, vector<int>(N+1,0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++){
            C[i][j] = C[i][j-1] + trains[i][j];
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int sum = 0;
        for (int j = p[i]; j <= q[i]; j++)
        {
            sum += C[j][q[i]] - C[j][p[i]-1];
        }
        cout << sum << endl;
    }

    return 0;
}
