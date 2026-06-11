#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

vector<string> split(const string &s,char c=' '){
    vector<string> ret;
    stringstream ss(s);
    string t;
    while(getline(ss,t,c)){
        ret.push_back(t);
    }
    return ret;
}

bool dp[16020], tmp[16020];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int x, y;
    cin >> s >> x >> y;
    vector<string> t = split(s, 'T');
    vector<int> a, b;
    rep(i, 0, t.size()){
        if(i % 2 == 0) a.push_back(t[i].size());
        else b.push_back(t[i].size());
    }
    dp[8010 + a[0]] = true;
    rep(i, 1, a.size()){
        rep(j, 0, 16020) tmp[j] = false;
        rep(j, 0, 16020){
            if(dp[j]){
                tmp[j - a[i]] = true;
                tmp[j + a[i]] = true;
            }
        }
        swap(dp, tmp);
    }
    bool ans = dp[8010 + x];
    rep(i, 0, 16020) dp[i] = false;
    dp[8010] = true;
    rep(i, 0, b.size()){
        rep(j, 0, 16020) tmp[j] = false;
        rep(j, 0, 16020){
            if(dp[j]){
                tmp[j - b[i]] = true;
                tmp[j + b[i]] = true;
            }
        }
        swap(dp, tmp);
    }
    ans &= dp[8010 + y];
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}