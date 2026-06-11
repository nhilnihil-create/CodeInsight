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

    ll x,y,z,k;cin>>x>>y>>z>>k;
    vll a(x),b(y),c(z);
    rep(i,x) cin>>a[i];
    rep(i,y) cin>>b[i];
    rep(i,z) cin>>c[i];

    priority_queue<pair<ll,vll>> q;
    sort(all(a),greater<ll>());
    sort(all(b),greater<ll>());
    sort(all(c),greater<ll>());

    set<pair<ll,vll>> s;
    q.push(pair<ll,vll>(a[0]+b[0]+c[0],vll({0,0,0})));

    rep(i,k){
        auto cur = q.top();
        q.pop();
        cout<<cur.fi<<endl;

        if(cur.se[0] + 1 < x){
            ll sum = cur.fi - a[cur.se[0]] + a[cur.se[0] + 1];
            auto num =cur.se; num[0]++;
            auto d= pair<ll,vll>(sum,num);
            
            //seに同じものがある場合はスルー
            if(!s.count(d)) s.insert(d), q.push(d);
        }

        if(cur.se[1] + 1 < y){
            ll sum = cur.fi - b[cur.se[1]] + b[cur.se[1] + 1];
            auto num =cur.se; num[1]++;
            auto d= pair<ll,vll>(sum,num);
            
            //seに同じものがある場合はスルー
            if(!s.count(d)) s.insert(d), q.push(d);
        }

        if(cur.se[2] + 1 < z){
            ll sum = cur.fi - c[cur.se[2]] + c[cur.se[2] + 1];
            auto num =cur.se; num[2]++;
            auto d= pair<ll,vll>(sum,num);
            
            //seに同じものがある場合はスルー
            if(!s.count(d)) s.insert(d), q.push(d);
        }
    }

}