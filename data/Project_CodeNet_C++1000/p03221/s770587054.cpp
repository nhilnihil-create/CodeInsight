#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> years(M);
    int Pi, Yi;
    for (int i = 0; i < M; i++)
    {
        cin >> Pi >> Yi;
        years.at(i) = make_tuple(Yi, Pi, i);
    }

    sort(years.begin(), years.end());

    vector<pair<int, int>> cities(M);
    vector<int> idx_in_pref(N, 0);
    for (auto &&year : years)
    {
        int i = get<2>(year), Pi = get<1>(year);
        int idx = ++idx_in_pref.at(Pi - 1);
        cities.at(i) = make_pair(Pi, idx);
    }

    for (auto &&city : cities)
    {
        int Pi = city.first, idx = city.second;
        printf("%06d%06d\n", Pi, idx);
    }
}