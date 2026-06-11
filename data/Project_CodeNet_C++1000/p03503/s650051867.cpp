#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;


//二進数に変換
void change(int n, vector<bool> &V){
  int i = 0;
  while(n > 0){
    int x;
    x = n%2;
    V[i] = x;
    n /= 2;
    i++;
  }
}

int main(){
  int N;
  cin >> N;
  int ans = -10000000000;
  
  vector<vector<bool>> inf(100, vector<bool> (10, false));
  rep(i, N){
    rep(j, 10){
      int F;
      cin >> F;
      if(F == 1){
        inf[i][j] = true;
      }
    }
  }
  
  vector<vector<int>> benefit(N, vector<int> (11));
  rep(i, N){
    rep(j, 11){
      int P;
      cin >> P;
      benefit[i][j] = P;
    }
  }
  
  for(int i = 1; i < 1024; i++){//営業時間を決める
    vector<bool> V(10, false);//初期化
    change(i, V);
    //チェック
     //rep(i, 10){
       //cout << V[i];
   // }
    //cout << endl;
    
    int sum = 0;
    
    rep(j, N){//店を決める      
      //被っている回数を数える
      int counter = 0;
      rep(k, 10){
        if(V[k] == true && inf[j][k] == true){
          counter++;
        }
      }
     //cout << j << " " << counter << endl;//テスト
      
      //cout << benefit[j][counter] << endl;
      sum += benefit[j][counter];
    }
    
   //cout << sum << endl;//テスト
    
    ans = max(ans, sum);
  }
  
  cout << ans << endl;
}
       