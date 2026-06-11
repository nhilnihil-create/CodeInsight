#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }

    sort(A.begin(), A.end(), greater<int>());
    map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        m[A.at(i)]++;
    }

    int u = 1 << 30, l = 1 << 29;
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        if (m.at(A.at(i)) == 0)
            continue;
        m.at(A.at(i))--;
        while (A.at(i) < l)
        {
            u >>= 1;
            l >>= 1;
        }
        if (m[u - A.at(i)] > 0)
        {
            res++;
            m[u - A.at(i)]--;
        }
    }
    cout << res << endl;
    return 0;
}
