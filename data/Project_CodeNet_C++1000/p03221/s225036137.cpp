//---------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#include<algorithm>
//---------------------------------------------------------------
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define SIZE 100005
#define INF 1000000000000000LL
#define all(x) x.begin(),x.end()
#define fi first
#define se second
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
//---------------------------------------------------------------
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin>>n>>m;
    vec p(m);
    vec y(m);
    
    rep(i,m){
        cin>>p[i]>>y[i];
    }

    vector<vector<int>> v(n+1);
    rep(i,m){
        v[p[i]].push_back(y[i]);
    }
    rep1(i,n){
        sort(all(v[i]));
    }

    rep(i,m){
        printf("%06d",p[i]);
        printf("%06d\n", lower_bound(all(v[p[i]]) ,y[i]) - v[p[i]].begin() + 1);
    }
}