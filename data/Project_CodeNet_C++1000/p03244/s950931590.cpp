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
//#include <atcoder/all>
//using namespace atcoder;
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
    int n; cin >> n;
    int m = 100001;
    vector<P> ar(m);
    vector<P> al(m);
    rep(i,m){
        ar[i] = P(0,i);
        al[i] = P(0,i);
    }
    rep(i,n){
        int a; cin >> a;
        if (i % 2 == 0) ar[a].first++;
        else al[a].first++; 
    }
    sort(ar.rbegin(),ar.rend());
    sort(al.rbegin(),al.rend());
    if (ar[0].second != al[0].second){
        cout << n - ar[0].first - al[0].first << endl;
    }
    else {
        cout << min(n-ar[1].first-al[0].first,n-ar[0].first-al[1].first) << endl;
    }
}