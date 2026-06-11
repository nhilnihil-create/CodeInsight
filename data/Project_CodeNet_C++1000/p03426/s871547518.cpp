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
#define INF 1e18
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define vec vector
using pint = pair<int,int>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
//---------------------------------------------------------------
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const double pi = acos(-1);
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll h,w,d,q;
    cin>>h>>w>>d;
    vector<pint> num(100009);
    rep(i,h)rep(j,w){
        int a;
        cin>>a;
        num[a]={i+1,j+1};
    }

    vll dp(100009);
    dp[0]=0;
    for(ll i=d;i<=h*w;i++){
        dp[i]=dp[i-d]+abs(num[i-d].fi-num[i].fi)+abs(num[i-d].se-num[i].se);
    }

    cin>>q;
    rep(i,q){
        ll l,r;
        cin>>l>>r;
        ll ans=dp[r]-dp[l];
        cout<<ans<<endl;
    }

}