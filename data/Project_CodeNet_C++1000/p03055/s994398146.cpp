#include <iostream>
  #include <algorithm>
  #include <vector>
  #include <cmath>
#include <string>
  #include <set>
  #include <map>
  #include <unordered_map>
  #include <iomanip>
  #include <stack>
  #include <queue>
  #include <deque>
  using namespace std;
  vector <int> g[200005];
  bool used[200005];
  int dst[200005];
  void solve(int k){
      for (int i = 0; i <= 200005; i++) {
          dst[i] = -1;
          used[i]=0;
      }
      queue <int> q;
      q.push(k);
      used[k] = true;
      dst[k] = 0;
      while (!q.empty()) {
          int cur = q.front();
          q.pop();
          for (int neighbor: g[cur]) {
              if (!used[neighbor]) {
                  q.push(neighbor);
                  used[neighbor] = true;
                  dst[neighbor] = dst[cur] + 1;
              }
          }
      }
  }
    int main(){
        int n;
        cin>>n;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        solve(1);
        int mx=0;
        int pos=1;
        for(int i=2;i<=n;i++){
            if(dst[i]>mx){
                mx=dst[i];
                pos=i;
            }
        }
        solve(pos);
        mx=0;
        pos=1;
        for(int i=1;i<=n;i++){
            if(dst[i]>mx){
                mx=dst[i];
                pos=i;
            }
        }
        if(mx%3==1){
            cout<<"Second";
            return 0;
        }
        cout<<"First";
        return 0;
}
