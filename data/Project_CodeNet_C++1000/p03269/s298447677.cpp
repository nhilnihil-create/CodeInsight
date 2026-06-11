#include <bits/stdc++.h>
using namespace std;

int main()
{
    int L;
    cin >> L;

    int N = 0;
    int remain = L;
    while (L > 0)
    {
        N++;
        L /= 2;
    }
    remain -= 1 << (N - 1);

    vector<vector<int>> edges;
    for (int i = 1; i < N; i++)
    {
        edges.push_back(vector<int>{i, i + 1, 0});
        edges.push_back(vector<int>{i, i + 1, 1 << (N - i - 1)});
    }

    bitset<32> b(remain);
    int w = 1 << (N - 1);
    for (int i = 25; i >= 0; i--)
    {
        if (b[i])
        {
            edges.push_back(vector<int>{1, N - i, w});
            w += 1 << i;
        }
    }

    cout << N << " " << edges.size() << endl;
    for (auto itr = edges.begin(); itr != edges.end(); itr++)
    {
        cout << (*itr)[0] << " " << (*itr)[1] << " " << (*itr)[2] << endl;
    }
}
