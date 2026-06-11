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

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

vector<int>bitSearch(int bit,int n){
    vector<int>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}


ll cost[400][400];
int main(){
   int h, w, d;
   cin >> h >> w >> d;
   vector<P>coord(h * w + 100);
   rep(i, h){
       rep(j, w){
           int a;
           cin >> a;
           coord[a] = P(i, j);
       }
   }
   vector<ll>rui_sum(h * w + 1, 0);
   vector<bool>seen(h * w + 1, false);
   REP(i, 1, h * w){
       int now = i;
       if(seen[i])continue;
       while(now + d <= h * w){
           seen[now] = true;
           rui_sum[now + d] = rui_sum[now] + abs(coord[now + d].first - coord[now].first) + abs(coord[now + d].second - coord[now].second);
           now += d;
       }
   }

   int q;
   ll res = 0;
   cin >> q;
   while(q--){
       int l, r;
       cin >> l >> r;
       cout << rui_sum[r] - rui_sum[l] << endl;
   }
}

