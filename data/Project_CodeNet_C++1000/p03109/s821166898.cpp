#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

// python でいうところの s.split(c)
vector<string> split(string s, char c){
    vector<string> res;
    s.push_back(c); // 番兵
    ll n = s.size();
    string cur;
    for(ll i = 0; i < n; i++) {
        if(s[i] == c) {
            res.push_back(cur);
            cur = "";
        } else {
            cur.push_back(s[i]);
        }
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    auto v = split(s, '/');
    bool f = true;
    if(v[0] > "2019") f = false;
    if(v[0] == "2019" && v[1] > "04") f = false;
    if(f) cout << "Heisei" << endl;
    else cout << "TBD" << endl;
}

int main() {
    ll t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}