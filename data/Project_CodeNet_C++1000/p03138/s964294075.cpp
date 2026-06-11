#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    ll k; cin>>k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<vector<ll>> dp(70, vector<ll>(2, -1));
    dp[51][0] = 0;
    for(int d=50; d>=0; d--){
        ll base = (1LL << d);
        int cnt1 = 0;
        for(int i=0; i<n; i++){
            if(base & a[i]) cnt1++;
        }

        if(dp[d+1][1] >= 0){
            // 未満フラグが既に立っている
            chmax(dp[d][1], dp[d+1][1] + base * max(cnt1, n - cnt1));
        }

        if(dp[d+1][0] >= 0){
            if(k & base){
                // 0 にして、未満フラグを立てる
                chmax(dp[d][1], dp[d+1][0] + base * cnt1);

                // 1 にして、未満フラグを立てない
                chmax(dp[d][0], dp[d+1][0] + base * (n - cnt1));
            }
            else{
                // 0 にせざるを得ず、未満フラグを立てられない
                chmax(dp[d][0], dp[d+1][0] + base * cnt1);
            }
        }
    }

    cout << max(dp[0][0], dp[0][1]) << endl;
    
    return 0;
}