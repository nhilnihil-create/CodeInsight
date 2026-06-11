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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define SIZE 100005
#define INF 1000000000000000LL
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m; cin>>n>>m;
    vec b(n+5,0);
    rep(i,m){
        int l,r; cin>>l>>r;
        b[l]++; b[r+1]--;

    }

    for(int j=1; j<n; j++) b[j+1]+=b[j];

    int ans=0;
    for(int i=1; i<=n; i++){
        if(b[i]==m) ans++;
    }

    cout<<ans<<endl;
}