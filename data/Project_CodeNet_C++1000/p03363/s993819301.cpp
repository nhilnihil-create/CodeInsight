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
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;



int main(){
    int n;
    cin >> n;
    VEC(ll, a, n);

    ll res = 0;

    vector<ll> sum(n, 0);
    rep(i, n){
        //if(a[i] == 0)res++;
        if(i == 0)sum[i] = a[i];
        else sum[i] = sum[i - 1] + a[i];
    }
    map<ll, ll> mp;
    rep(i, n){
      //cout << sum[i] << endl;
        mp[sum[i]]++;
    }

    for(auto m : mp){
      //cout << m.first << " " << m.second << endl;
      if(m.first == 0)res += m.second;
        res += (m.second * (m.second - 1) / 2);
    }
    cout << res << endl;
}