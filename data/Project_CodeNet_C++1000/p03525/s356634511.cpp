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
     
const int MOD = 1e9 + 7;

vector<ll>bitSearch(int bit,int n){
    vector<ll>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    S.push_back(1e9);
    return S;
}


int main(){
   int n;
   cin >> n;
   if(n >= 24){
      cout << 0 << endl;
      return 0;
   }
   vector<int> a(n);
   rep(i, n)cin >> a[i];
   vector<int> d(50, 0), list;

   rep(i, n){
      d[a[i]]++;
   }

   int res = 0;
   d[0]++;
   rep(i, 13){
      if(d[i] > 0)list.push_back(i);
      if(d[i] > 2 || (i % 12 == 0 && d[i] > 1)){
         cout << 0 << endl;
         return 0;
      }
   }
   
   for(int bit = 0; bit <= (1 << list.size()); bit++){
      auto S = bitSearch(bit, (int)list.size());
      auto tmp = list;
      int sz = tmp.size();
      rep(i, sz){
         int now = tmp[i];
         if(i == *lower_bound(ALL(S), i))tmp[i] = (24 - tmp[i]) % 24;
         if(d[now] == 2)tmp.push_back((24 - tmp[i]) % 24);
      }
      int dif = INF;
      sort(ALL(tmp));
      rep(i, (int)tmp.size()){
         REP(j, i + 1, (int)tmp.size() - 1){
            int t = abs(tmp[i] - tmp[j]);
            int d = min(t, 24 - t);
            chmin(dif, d);
         }
      }
      chmax(res, dif);
   }
   cout << res << endl;
}
