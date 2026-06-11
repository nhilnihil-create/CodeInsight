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

void yes(){
    cout << "Yes" << endl;
}

void no (){
    cout << "No" << endl;
}

ll cel (ll a, ll b){
    if (a % b == 0) return a / b;
    else return a / b + 1;
}

ll gcds(ll a, ll b){
    ll c = a % b;
    while (c != 0){
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}



int main() {
    int n, m; cin >> m >> n;
    vector<int> ar(n);
    rep(i,n) cin >> ar[i];
    sort(ar.begin(),ar.end());
    vector<int> sa(n-1);
    rep(i,n-1) sa[i] = ar[i+1] - ar[i];
    sort(sa.rbegin(),sa.rend());
    if (n <= m) cout << 0 << endl;
    else {
        int ans = ar[n-1] - ar[0];
        rep(i,m-1) ans -= sa[i];
        cout << ans << endl; 
    }
}