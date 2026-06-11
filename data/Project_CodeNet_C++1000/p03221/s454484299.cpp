#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N, M;
    cin >> N >> M;

    /* 県ごとの市のマップ */
    map<int, vector<pair<int, int>>> city_map;
    int p, y;
    for ( int i=0; i<M; i++ ) {
        cin >> p >> y;
        city_map[p].push_back(make_pair(y, i));
    }

    /* 元 index 順に <県 No., 市の順番> を格納する */
    vector<pair<int, int>> ans(M);

    int pref, original_idx;
    vector<pair<int, int>> cities;
    /* 県をすべて巡回する */
    for ( pair<int, vector<pair<int, int>>> itr : city_map ) {
        pref = itr.first;
        cities = itr.second;
        /* 市を年順に並び替える */
        sort(cities.begin(), cities.end());
        /* 各県の市を年順に巡回する */
        for ( int i=0; i<(int)cities.size(); i++ ) {
            original_idx = cities.at(i).second;
            ans[original_idx] = make_pair(pref, i + 1);
        }
    }

    for ( int i=0; i<M; i++ )
        printf("%06d%06d\n", ans.at(i).first, ans.at(i).second);

    return 0;
}
