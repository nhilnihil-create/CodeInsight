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

    ll n;
    cin>>n;
    vec<string> s(n);
    rep(i,n)cin>>s[i];
    ll m=0,a=0,r=0,c=0,h=0;
    ll d[5];
    ll se1[10]={0,0,0,0,0,0,1,1,2,1};
    ll se2[10]={1,1,1,3,2,2,2,2,3,3};
    ll se3[10]={2,3,4,4,3,4,3,4,4,4};

    rep(i,n){
      if(s[i][0]=='M')m++;
      if(s[i][0]=='A')a++;
      if(s[i][0]=='R')r++;
      if(s[i][0]=='C')c++;
      if(s[i][0]=='H')h++;
    }

    d[0]=m;
    d[1]=a;
    d[2]=r;
    d[3]=c;
    d[4]=h;

    ll ans=0;
    rep(i,10){
      ans+=d[se1[i]]*d[se2[i]]*d[se3[i]];
    }

    cout<<ans<<endl;
}