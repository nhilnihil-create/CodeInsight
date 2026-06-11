#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<P> r(n), b(n);
    rep(i, n)cin >> r[i].first >> r[i].second;
    rep(i, n)cin >> b[i].first >> b[i].second;
    sort(r.begin(), r.end(), greater<P>());
    set<P> ans;
    for(P v : r){
        int x = v.first;
        int y = v.second;
        P mn = make_pair(1000, 1000);
        for(P t : b){
            if(x < t.first && y < t.second){
                if(t.second < mn.second && ans.find(t) == ans.end())mn = t;
            }
        }
        if(mn != make_pair(1000, 1000))ans.insert(mn);
    }
    cout << ans.size() << endl;
}