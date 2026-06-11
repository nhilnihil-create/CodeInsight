#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w, 0));
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      int k;
      cin >> k;
      a[i][j] = k%2;
    }
  }
  bool flag = false;
  vector<int> ans[4];
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(i==h-1&&j==w-1) continue;
      if(i%2){
        if(flag){
          if(a[i][w-j-1]){
            flag = false;
            continue;
          }
          if(j==w-1){
            ans[0].push_back(i+1);
            ans[1].push_back(1);
            ans[2].push_back(i+2);
            ans[3].push_back(1);
          }else{
            ans[0].push_back(i+1);
            ans[1].push_back(w-j);
            ans[2].push_back(i+1);
            ans[3].push_back(w-j-1);
          }
          continue;
        }
        if(a[i][w-j-1]){
          flag = true;
          if(j==w-1){
            ans[0].push_back(i+1);
            ans[1].push_back(1);
            ans[2].push_back(i+2);
            ans[3].push_back(1);
          }else{
            ans[0].push_back(i+1);
            ans[1].push_back(w-j);
            ans[2].push_back(i+1);
            ans[3].push_back(w-j-1);
          }
        }
      }else{
        if(flag){
          if(a[i][j]){
            flag = false;
            continue;
          }
          if(j==w-1){
            ans[0].push_back(i+1);
            ans[1].push_back(w);
            ans[2].push_back(i+2);
            ans[3].push_back(w);
          }else{
            ans[0].push_back(i+1);
            ans[1].push_back(j+1);
            ans[2].push_back(i+1);
            ans[3].push_back(j+2);
          }
          continue;
        }
        if(a[i][j]){
          flag = true;
          if(j==w-1){
            ans[0].push_back(i+1);
            ans[1].push_back(w);
            ans[2].push_back(i+2);
            ans[3].push_back(w);
          }else{
            ans[0].push_back(i+1);
            ans[1].push_back(j+1);
            ans[2].push_back(i+1);
            ans[3].push_back(j+2);
          }
        }
      }
    }
  }
  cout << ans[0].size() << endl;
  for(int i=0; i<ans[0].size(); i++){
    cout << ans[0][i] << " " << ans[1][i] << " " << ans[2][i] << " " << ans[3][i] << endl;
  }
  return 0;
}
