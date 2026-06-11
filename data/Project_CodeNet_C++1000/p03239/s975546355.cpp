#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, T, c, t;
    cin >> N >> T;
    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        cin >> c >> t;

        if (T >= t)
        {
            v.push_back(c);
        }
    }

    if (v.size() != 0)
    {
        sort(v.begin(), v.end());
        cout << v[0];
    }

    if (v.size() == 0)
    {
        cout << "TLE";
    }
}