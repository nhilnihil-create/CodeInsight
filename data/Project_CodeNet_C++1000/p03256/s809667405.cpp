#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    string s;
    cin >> s;
    vector <int> D[n+1], T;
    int S[n+1], A[n+1], B[n+1], G[n+1], k=0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i-1] == 'A')
        {
            S[i] = 0;
        }
        else
        {
            S[i] = 1;
        }
        A[i] = 0;
        B[i] = 0;
        G[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        D[a].push_back(b);
        D[b].push_back(a);
        if (S[a] == 1)
        {
            B[b]++;
        }
        else
        {
            A[b]++;
        }
        if (S[b] == 1)
        {
            B[a]++;
        }
        else
        {
            A[a]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (A[i] >= 1 && B[i] >= 1)
        {
            G[i] = 1;
            k++;
        }
        else
        {
            T.push_back(i);
        }
    }
    for (int i = 0; i < T.size(); i++)
    {
        a = T[i];
        for (int y = 0; y < D[a].size(); y++)
        {
            b = D[a][y];
            if (S[a] == 1)
            {
                B[b]--;
            }
            else
            {
                A[b]--;
            }
            if (G[b] == 1 && (A[b] == 0 || B[b] == 0))
            {
                k--;
                G[b] = 0;
                T.push_back(b);
            }
        }
    }
    if (k > 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}
