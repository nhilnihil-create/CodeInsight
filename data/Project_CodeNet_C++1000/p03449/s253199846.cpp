#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#include<cstdint>


     
#define INF 1e9
#define LINF 1e19
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define pb push_back
#define sz size()
     
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

     
const ll MOD = 1e9 + 7;
const ll ZER = 0;


int main(){
    int n;
    cin >> n;
    ll a[2][n + 1];
    a[0][n] = 0, a[1][n] = 0;
    rep(i, 2)rep(j, n)cin >> a[i][j];
    rep(i, n)a[0][i + 1] += a[0][i];
    rep(i, n)a[1][i + 1] += a[1][i];
    ll res = 0;
    rep(i, n){
        if(i != 0)chmax(res, a[0][i] + a[1][n] - a[1][i - 1]);
        else res = a[0][0] + a[1][n];
    }
    cout << res << endl;
}



