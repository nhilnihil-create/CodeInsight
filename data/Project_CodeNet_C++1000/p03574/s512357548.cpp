#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

void bom(int i, int j, vector<vector<int>> &V){
  V[i][j] = -100;
  for(int k = -1; k<=1; k++){
    for(int l = -1; l<=1; l++){
      V[i+k][j+l]++;
    }
  }
}
  

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<int>> V(60, vector<int> (60,0));
  rep(i,H){
    string s;
    cin >> s;
    rep(j,W){
      if(s[j]=='#'){
        bom(i+1,j+1,V);
      }
    }
    
  }
  
  rep(i,H){
    rep(j,W){
      
      if(V[i+1][j+1]>=0){
        cout << V[i+1][j+1];
      }
      else{
        cout << '#';
      }
    
    }
    cout << endl;
  }
}
      