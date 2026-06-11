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
    using ll = unsigned long long;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
     
const int MOD = 1e9 + 7;


int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
   int h, w;
   cin >> h >> w;
   vector<string> fld(h);
   rep(i, h)cin >> fld[i];
   bool all = true;
   rep(i, h)rep(j, w)if(fld[i][j] != '#')all = false;
   if(all){
      cout << 0 << endl;
      return 0;
   }
   vector<vector<int>> num(h, vector<int>(w, INF));


   rep(i, h){
      rep(j, w){
         if(fld[i][j] == '#')num[i][j] = 0;
         rep(d, 4){
            int ny = i + dy[d], nx = j + dx[d];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w)continue;
            if(fld[ny][nx] == '#')num[i][j] = 1;
            else num[i][j] = min(num[i][j], num[ny][nx] + 1);
         }
      }
      for(int j = w - 1; j >= 0; j--){
         rep(d, 4){
            int ny = i + dy[d], nx = j + dx[d];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w)continue;
            if(fld[ny][nx] == '#')num[i][j] = 1;
            else num[i][j] = min(num[i][j], num[ny][nx] + 1);
         }
      }
   }

   for(int i = h - 1; i >= 0; i--){
      rep(j, w){
         rep(d, 4){
            int ny = i + dy[d], nx = j + dx[d];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w)continue;
            if(fld[ny][nx] == '#')num[i][j] = 1;
            else num[i][j] = min(num[i][j], num[ny][nx] + 1);
         }
      }
      for(int j = w - 1; j >= 0; j--){
         rep(d, 4){
            int ny = i + dy[d], nx = j + dx[d];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w)continue;
            if(fld[ny][nx] == '#')num[i][j] = 1;
            else num[i][j] = min(num[i][j], num[ny][nx] + 1);
         }
      }
   }

   int res = 0;
   rep(i, h){
      rep(j, w){
         //cout << num[i][j] << " ";
         res = max(res, num[i][j]);
      }
      //cout << endl;
   }
   cout << res << endl;
}
