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
const int MOD = 998244353;
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

void yn(int o){
    if (o == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
}

int cul(int n){
    vector<int> ar(10,0);
    int re = 0;
    rep(i,10){
        ar[i] = n % 10;
        n /= 10;
        re += ar[i];
    }
    return re;
}

int main() {
    int n; cin >> n;
    vector<int> art(n);
    vector<P> xy(n);
    rep(i,n) cin >> art[i] >> xy[i].first >> xy[i].second;
    int ix = 0; int iy = 0; int it = 0;
    bool t = true;
    rep(i,n){
        int dt = art[i] - it;
        int dxy = abs(ix - xy[i].first) + abs(iy - xy[i].second);
        if (dxy > dt || (dt - dxy) % 2 == 1){
            t = false;
            break;
        } 
        ix = xy[i].first;
        iy = xy[i].second;
        it = art[i];
    }
    if (t) cout << "Yes" << endl;
    else cout << "No" << endl;
}