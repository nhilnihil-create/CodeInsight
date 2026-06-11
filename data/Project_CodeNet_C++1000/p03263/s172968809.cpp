#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int h, w;
  cin >> h >> w;
  bool odd = false;
  int y, x;
  vector<vector<int>> mat(h, vector<int>(w));
  rep(i, h){
    rep(j, w){
      cin >> mat[i][j];
    }
  }
  vector<string> vec;
  int cnt = 0;
  rep(i, h){
    if(i%2 == 0){
      rep(j, w){
        int num = mat[i][j];
        if(!odd){
          if(num % 2 == 1){
            odd = true;
            y = i+1; x = j+1;
          }
        }else{
          vec.push_back(to_string(y)+" "+to_string(x)+" "+to_string(i+1)+" "+to_string(j+1));
          y = i+1; x = j+1;
          cnt++;
          if(num % 2 == 1){
            odd = false;
          }
        }
      }
    }else{
      for(int j=w-1; j>=0; j--){
        int num = mat[i][j];
        if(!odd){
          if(num % 2 == 1){
            odd = true;
            y = i+1; x = j+1;
          }
        }else{
          vec.push_back(to_string(y)+" "+to_string(x)+" "+to_string(i+1)+" "+to_string(j+1));
          y = i+1; x = j+1;
          cnt++;
          if(num % 2 == 1){
            odd = false;
          }
        }
      }
    }
  }
  cout << cnt << endl;
  rep(i, vec.size()) cout << vec[i] << endl;
  return 0;
}
  
        
        
        
        