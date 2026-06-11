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
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
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

    ll n;cin>>n;
    vll t(n+1);
    vll x(n+1);
    vll y(n+1);
    t[0]=0;
    x[0]=0;
    y[0]=0;
    rep2(i,1,n){
        cin>>t[i]>>x[i]>>y[i];
    }

    rep(i,n){
        if(abs(x[i]-x[i+1])>t[i+1]-t[i] || abs(y[i]-y[i+1])>t[i+1]-t[i] || abs(x[i]-x[i+1])+abs(y[i]-y[i+1])>t[i+1]-t[i]) {
            cout<<"No"<<endl;
            return 0;
        }else{
            if((t[i+1]-t[i])%2 != ((x[i+1]+x[i]+y[i+1]+y[i])%2)){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    cout<<"Yes"<<endl;
}