#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> ab(M);
    for (int i = 0; i < M; i++)
    {
        cin >> ab[i].second >> ab[i].first;
        ab[i].second--, ab[i].first--;
    }

    sort(ab.begin(), ab.end());

    long long int ans = 0;
    int t = -1;
    for (int i = 0; i < M; i++)
    {
        if (t <= ab[i].second)
        {
            ans++;
            t = ab[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}