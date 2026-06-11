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
     
    #define INF 1e18
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
    #define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
    #define vec(type,n) vector<type>(n)
    #define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
    #define ALL(a)  (a).begin(),(a).end()
     
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
     
const int MOD = 1e9 + 7;


ll dp[200010];
int main(){
   int n;
   cin >> n;
   vector<int> a(n);
   rep(i, n)cin >> a[i];
   vector<int> tab(200010, -1);
   dp[0] = 1;
   rep(i, n){
      if(tab[a[i]] == -1 || tab[a[i]] == i){
         dp[i + 1] = dp[i] % MOD;
      }
      else {
         dp[i + 1] = (dp[i] + dp[tab[a[i]]]) % MOD;
      }
      tab[a[i]] = i + 1;
   }
   cout << dp[n] << endl;
}
