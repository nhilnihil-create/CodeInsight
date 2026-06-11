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
     
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
     
const ll MOD = 1e9 + 7;
//最大公約数
ll gcd(ll a, ll b){
  if(b == 0)return a;
  else return gcd(b, a % b);
}


int dp[100][2];
int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    rep(i, n)cin >> x[i] >> y[i] >> z[i];
    vector<vector<ll>> d(8, vector<ll>(n, - INF * INF));
    rep(i, n){
        int cnt = 0;
        rep(xx, 2){
            rep(yy, 2){
                rep(zz, 2){
                    d[cnt][i] = pow(-1, xx) * x[i] + pow(-1, yy) * y[i] + pow(-1, zz) * z[i];
                    cnt++;
                }
            }
        }
    }
    
    rep(i, 8)sort(ALL(d[i]), greater<ll>());
    ll res = 0;
    rep(i, 8){
        ll sum = 0;
        rep(j, m){
            sum += d[i][j];
        }
      //cout << sum << endl;
        chmax(res, sum);
    }
    cout << res << endl;
  //rep(i, 8){rep(j, n)cout << d[i][j] << " ";cout << endl;}
}



