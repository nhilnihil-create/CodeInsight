#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Pxy = pair<double, double>;
using T = tuple<int, int, bool>;
const int INF = 1001001007;
const int MOD = 1000000007;
//const int MOD = 998244353;
const ll inf = 1e18;
template <typename AT>
void printvec(vector<AT> &ar){
    rep(i,ar.size()-1) cout << ar[i] << " ";
    cout << ar[ar.size()-1] << endl;
}
template <typename Q>
void printvvec(vector<vector<Q>> &ar){
    rep(i,ar.size()){
        rep(j,ar[0].size()-1) cout << ar[i][j] << " ";
        cout << ar[i][ar[0].size()-1] << endl;
    }
}
template <typename S>
bool range(S a, S b, S x){
    return (a <= x && x < b);
}

int main() {
    string s; cin >> s;
    int n = s.size();
    vector<int> ar;
    rep(i,n-1){
        if (s.substr(i,2) == "BC"){
            ar.emplace_back(i);
        }
    }
    rep(i,ar.size()){
        s.replace(s.begin()+ar[ar.size()-1-i],s.begin()+ar[ar.size()-1-i]+2,"S");
    }
    s += 'B';
    n = s.size();
    vector<string> pq;
    string ps = "";
    rep(i,n){
        if ((s[i] == 'B' || s[i] == 'C') && !ps.empty()){
            pq.emplace_back(ps);
            ps = "";
        }
        else if (s[i] == 'S'|| s[i] == 'A'){
            ps += s[i];
        }
        //cout << ps << endl;
    }
    //printvec(pq);
    ll ans = 0;
    rep(i,pq.size()){
        int d = pq[i].size();
        string g = pq[i];
        //cout << g << endl;
        int cnt = 0;
        rep(j,d){
            if (g[j] == 'S'){
                ans += j - cnt;
                //cout << ans << "#" << endl;
                cnt ++;
            }
        }
    }
    cout << ans << endl;
}
