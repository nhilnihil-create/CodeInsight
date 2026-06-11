#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <tuple>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <random>
#include <set>
#include <stack>

//#include <bits/stdc++.h>
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,i0,n) for(int (i)=(i0);(i)<(n);(i)++)
#define FORR(i,i0,n) for(int (i)=(n)-1; (i)>=(i0);(i)--)
#define SORT(x) sort(x.begin(),x.end())
#define SORTR(x) sort(x.begin(),x.end(),greater<int>())
#define rn return
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#include <time.h>
typedef std::pair<int,int> pii;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;
using namespace std;
using ll = long long;
#define PI 3.14159265358979323846264338327950L
const int mod = 1000000007;




void solve(){
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    
    map<int,ll> memo;
    vector<ll> dp(n,0);
    dp[0] = 1;
    memo[c[0]] = 1;
    for(int i = 1; i < n; i++){
        if (c[i] == c[i-1]) dp[i] = dp[i-1];
        else{
            dp[i] = dp[i-1];
            dp[i] += memo[c[i]];
            memo[c[i]] += dp[i-1];
            memo[c[i]] %= mod;
            dp[i]%=mod;
        }
    }
    cout << dp.back();
    
}

int main(){
    int T;
    T = 1;
    while(T--){
        solve();
        cout << endl;
    }
}




