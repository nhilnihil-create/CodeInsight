#include "bits/stdc++.h"

using ll = long long;
using namespace std;

const int N = 1001;
bool visited[N][N];

void solveCase() {
   int n, m;
   cin >> n >> m;
   vector <string> v(n);
   for(int i = 0; i < n; i++) {
      cin >> v[i];
   }
   deque <pair <pair <int, int>, int>> d;

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         if(v[i][j] == '#') {
            d.push_back({{i, j}, 0});
            visited[i][j] = true;
         }
      }
   }

   int ans = 0;

   while(!d.empty()) {
      auto t = d.front();
      d.pop_front();
      int r = t.first.first;
      int c = t.first.second;
      int dist = t.second;
      ans = max(ans, dist);
      
      for(int i = -1; i <= 1; i++) {
         for(int j = -1; j <= 1; j++) {
            if(abs(i) + abs(j) == 1) {
               int r_ = r + i;
               int c_ = c + j;
               if(r_ >= 0 && r_ < n && c_ >= 0 && c_ < m) {
                  if(visited[r_][c_] == false) {
                     visited[r_][c_] = true;
                     d.push_back({{r_, c_}, dist + 1});
                  }
               }
             }
         }
      }
   }

   cout << ans << endl;

}


int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   
   int testcase = 1;
   // cin >> testcase;
 
   for(int i = 0; i < testcase; i++) {
      solveCase();
   }
 
   return 0;
}
