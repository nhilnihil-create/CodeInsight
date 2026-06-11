#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    string s, t;
    cin >> s >> t;
    map<char, int> ms;
    map<char, int> mt;
    int n = s.size();
    rep(i, n) {
        ms[s[i]]++;
        mt[t[i]]++;
    }
    string ans = "Yes";
    vector<int> ns;
    vector<int> nt;
    for (auto m: ms) ns.push_back(m.second);
    for (auto m: mt) nt.push_back(m.second);
    sort(whole(ns));
    sort(whole(nt));
    if (ns.size()!=nt.size()) ans = "No";
    else {
        rep(i, ns.size()) {
            if (ns[i]!=nt[i]) ans = "No";
        }
    }
    
    cout << ans << endl;
    return 0;
}
