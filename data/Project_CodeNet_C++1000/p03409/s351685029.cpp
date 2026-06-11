#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const ll INFL = (1LL << 60);
 const int INFI = (1 << 30);

 int main() {
      int N; cin >> N;
      vector<pair<int,int>> BA, CD;
      rep(i, 0, N){
          int x, y; cin >> x >> y;
          BA.push_back({y,x});
      }
      rep(i, 0, N){
          int x, y;cin >>  x >> y;
          CD.push_back({x,y});
      }

      sort(BA.begin(), BA.end(), greater<pair<int, int>>());
      sort(CD.begin(), CD.end());

      vector<bool> f(N, false);

      //cの小さい順
      rep(i, 0, N){
          int c = CD.at(i).first;
          int d = CD.at(i).second;
          //bの大きい順
          rep(j, 0, N){
              int a = BA.at(j).second;
              int b = BA.at(j).first;

              if(f.at(j)) continue;
              if(a < c && b < d){
                  f.at(j) = true;
                  break;
              }
          }
      }

      int cnt =0;
      rep(i, 0, N) if(f.at(i)) cnt++;

      cout<<cnt<<endl;
  }
