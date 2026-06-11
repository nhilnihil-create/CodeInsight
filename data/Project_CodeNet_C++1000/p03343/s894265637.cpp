#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, K, q, M=2000000000;
    cin >> n >> K >> q;
    int A[n+1];
    vector <int> V;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    A[n] = -1;
    priority_queue <int, vector<int>, greater<int>> Q, QV;
    for (int i = 0; i < n; i++)
    {
        for (int y = 0; y <= n; y++)
        {
            if (A[y] < A[i])
            {
                while (Q.size() >= K)
                {
                    QV.push(Q.top());
                    Q.pop();
                }
                while (Q.size() > 0)
                {
                    Q.pop();
                }
            }
            else
            {
                Q.push(A[y]);
            }
        }
        if (QV.size() >= q)
        {
            for (int y = 0; y < q-1; y++)
            {
                QV.pop();
            }
            M = min(M, QV.top()-A[i]);
        }
        while (QV.size() > 0)
        {
            QV.pop();
        }
    }
    cout << M;
    return 0;
}
