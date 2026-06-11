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
const ll zer = 0;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll sa = 0, sb = 0;
    rep(i, n){
      cin >> a[i];
      sa += a[i];
    }
    rep(i, n){
      cin >> b[i];
      sb += b[i];
    }
    if(sa < sb){
      cout << -1 << endl;
      return 0;
    }

    vector<ll> dif(n);
    rep(i, n)dif[i] = a[i] - b[i];
    sort(ALL(dif), greater<ll>());
    vector<ll> q;
    ll sum = 0;
    rep(i, n){
      if(dif[i] >= 0){
        q.push_back(dif[i]);
      }
      sum += dif[i];
    }
    sort(ALL(q));
    ll res = 0;
    rep(i, (int)q.size()){
      if(sum >= q[i]){
        res++;
        sum -= q[i];
      }
    }
    cout << n - res << endl;
}



