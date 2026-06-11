#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i <(int)(n); i++)
using namespace std;

int main(){
  
  //N,Mが10以下なので全探索でも間に合う
  
  int N,M;
  cin >> N >> M;
  vector<vector<int>>S(12,vector<int>(12));
  vector<int>P(M);
  vector<int>K(M);
  int k;
  
  rep(i,M){
    cin >> K[i];
    int a = K[i];
    rep(j,a){
      cin >> S[i][j];
    }
  }
  
  rep(i,M)cin >> P[i];
  
  //bit全探索
  int ans = 0;
  
  for(int bit = 0; bit < (1 << N); bit++){
    //スイッチの組み合わせを全探索。bitが立っているところのスイッチが起動している
    bool flag = true;
    //M個の電球についてみていく
    rep(i,M){
      int num = 0;
      //スイッチの条件(num % 2 == P[i])が一致している時だけ先に進む
      int k = K[i];
      rep(j,k){
        int now = S[i][j] - 1;
        if(bit & (1 << now))num++;
      }
      if(num % 2 != P[i]){
        flag = false;
      }
    }
    if(flag)ans++;
    
  }
  
  cout << ans << endl;
  
}