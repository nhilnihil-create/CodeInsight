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

void yes(int n){
    cout << "Yes" << endl;
}

void no (int n){
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

int div2(ll a){
    int ans = 0;
    while (a % 2LL == 0){
        a /= 2LL;
        ans++;
    }
    return ans;
}

int div5(ll b){
    int ans = 0;
    while (b % 5LL == 0){
        b /= 5LL;
        ans++;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> ar(n);
    rep(i,n) cin >> ar[i];
    vector<int> al(n);
    rep(i,n) al[i] = ar[i];
    sort(al.begin(),al.end());
    int midl = al[n/2 - 1];
    int midr = al[n/2];
    rep(i,n){
        if (ar[i] <= midl) cout << midr << endl;
        else if (ar[i] >= midr) cout << midl << endl;
    }
}