#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000000
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> ab,cd;
    map<pair<int, int>, int> mp;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        ab.emplace_back(a, b);
    }
    rep(j,n){
        int c, d;
        cin >> c >> d;
        cd.emplace_back(c, d);
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    int cnt = 0;
    rep(i,n){
        pair<int, int> p = make_pair(cd[i].first, -1);
        auto it = lower_bound(ab.begin(), ab.end(), p);
        for (auto it1 = ab.begin(); it1 < it;it1++){
            auto e = *it1;
            if(e.second >= p.second && e.second < cd[i].second){
                p = e;
            }
        }
        it = find(ab.begin(), ab.end(), p);
        if(it != ab.end()){
            ab.erase(it);
            cnt++;
        }
    }
    cout << cnt << endl;
}
