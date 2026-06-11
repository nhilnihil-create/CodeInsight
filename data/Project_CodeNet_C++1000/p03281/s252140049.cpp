#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  int anscount = 0;
  int max = 0;
  
  for(int i = 1; i <= N; i++){
    anscount = 0;
    if(i %2 != 0){//奇数のみ取得
      //その奇数を1からiまで割り続けて割り切れる値が何個あるか考える
      int gg = i;
      while(gg){//iがゼロになるまで
        if(i %gg == 0){
          anscount++;
          gg--;
        }else{
          gg--;
        }
      }
      if(anscount >= 8){
         max++;
      }
    }
  }
  cout << max << endl;

}