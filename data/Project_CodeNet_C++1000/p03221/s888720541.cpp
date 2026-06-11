#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using tup = tuple<int,int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<tup> city(m);
    rep(i,m) {
        int p, y;
        cin >> p >> y;
        city.at(i) = make_tuple(i, p, y);
    }
    sort(city.begin(), city.end(), [](tup x, tup y) {
        if (get<1>(x) == get<1>(y)) return get<2>(x) < get<2>(y);
        return get<1>(x) < get<1>(y);
    });
    vector<string> ans(m);
    int p = 0, id = 0;
    rep(i,m) {
        if (p == get<1>(city.at(i))) id++;
        else id = 1;
        p = get<1>(city.at(i));
        ostringstream pss, idss;
        pss << setfill('0') << setw(6) << p;
        idss << setfill('0') << setw(6) << id;
        ans.at(get<0>(city.at(i))) = pss.str() + idss.str();
    }
    rep(i,m) cout << ans.at(i) << endl;
    return 0;
}