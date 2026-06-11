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
const int mod = 1000000007;
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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int le = 0;
    int ri = 0;
    int ans = 1;
    int so = 0; if (s[0] == '0') so++;
    while (ri != n-1){
        int x = so;
        if (s[ri] == '1' && s[ri+1] == '0') x++;
        if (x <= k){
            ri++;
            so = x;
        }
        else {
            if (s[le] == '0' && s[le+1] == '1') so--;
            le++;
        }
        ans = max(ans,ri-le+1);
        //cout << le << " " << ri << " " << so << endl;
    }
    cout << ans << endl;
}