#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
using vi = vector<int>;
template <class T>
using Grid = vector<vector<T>>;

int main(){
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> v; // pref, year, city
    v.reserve(M);
    rep(i, M) {
        int p,y;
        cin >> p >> y;
        v.emplace_back(p, y, i);
    }
    sort(v.begin(), v.end());
    int prevpref = -1;
    int count;
    vector<tuple<int, int, int>> ans; // city, pref, num
    ans.reserve(M);
    for (auto x : v) {
        if (get<0>(x) != prevpref)
            count = 0;
        prevpref = get<0>(x);
        count++;
        ans.emplace_back(get<2>(x), prevpref, count);
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans) {
        printf("%06d%06d\n", get<1>(x), get<2>(x));
    }
}