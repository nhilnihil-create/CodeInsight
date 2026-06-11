#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, p, y;
    cin >> n >> m;
    vector<tuple<int, int, int>> v;
    for(int i = 0; i < m; ++i) {
        cin >> p >> y;
        v.push_back(make_tuple(p, y, i));
    }
    sort(v.begin(), v.end());
    int num = 1;
    get<1>(v[0]) = 1;
    for(int i = 1; i < m; ++i) {
        num++;
        if(get<0>(v[i]) != get<0>(v[i-1])) num = 1;
        get<1>(v[i]) = num;
    }
    for(int i = 0; i < m; ++i) swap(get<0>(v[i]), get<2>(v[i]));
    sort(v.begin(), v.end());
    for(int i = 0; i < m; ++i) 
        printf("%06d%06d\n", get<2>(v[i]), get<1>(v[i]));

    return 0;
}
