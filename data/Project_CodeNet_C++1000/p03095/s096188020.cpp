#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

constexpr ll mod = 1000000000 + 7;
#define NMAX 100010

/*
How to use:
- input :   std::string
- output :  std::vector<std::pair<char, long long>>
    - first:    character
    - second:   count

Note that any element of input must not be -1.
*/
vector<pair<char,ll>> run_length_encoding(string s){
    vector<pair<char,ll>> res;
    ll n = s.size();
    char prev = -1;
    ll cur = 1;
    for(ll i = 0; i < n; i++) {
        if(prev == s[i]) cur++;
        else {
            if(prev != -1) res.push_back({prev, cur});
            prev = s[i];
            cur = 1;
        } 
    }
    res.push_back({prev, cur});
    return res;
}

vector<ll> rec(30, -1);

ll dfs(vector<vector<ll>> &a, ll itr) {
    if(itr == 26) return 1;
    if(rec[itr] != -1) return rec[itr];
    ll res = 0;
    for(auto e : a[itr]) {
        res += e * dfs(a, itr+1);
        res %= mod;
    }
    return rec[itr] = res;
}

int main(){
    ll n;
    string s;
    cin >> n >> s;
    auto v = run_length_encoding(s);
    vector<vector<ll>> a(26);
    rep(i, 0, 26) a[i].push_back(1);
    for(auto e : v) {
        a[e.first-'a'].push_back(e.second);
    }
    cout << (dfs(a, 0)-1+mod)%mod << endl;
    return 0;
}