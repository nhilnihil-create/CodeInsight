#include<string>
#include<iostream>
#include <algorithm>
#include<vector>
#include<functional>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <numeric>
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
using namespace std;



int main() {
    ll N, T;
    ll ans_cost, ans_time = 0;
    cin >> N >> T;
    vector<ll> c(N, 0);
    vector<ll> t(N, 0);
    rep(i, N) cin >> c[i] >> t[i];
    ans_cost = c[0];
    rep(j, N) {
        if (ans_cost >= c[j]&& t[j]<=T) {
            ans_cost = c[j];
            ans_time = t[j];
        }
    }
    sort(t.begin(), t.end());
    if (t[0] > T) {
        cout << "TLE" << endl;
        return 0;
    }
     cout << ans_cost << endl;
    

  

    return 0;
}
