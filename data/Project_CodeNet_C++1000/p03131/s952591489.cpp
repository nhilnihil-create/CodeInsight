#include <bits/stdc++.h>
using namespace std;

int main() {
  long long num, Yen, Bis;
  long long cnt = 1;
  long long hYen = 0;
  
  cin >> num >> Yen >> Bis;
  
  if(Yen+1 >= Bis){
    // 増やし続ける
    cnt += num;
  }else{
    // 円→ビスケットに交換する
    for(int i = 0; i < num; i++){
      if(i == 0 && num % 2 == 1){
        // 奇数でラストはビスケット増やして終わり
        cnt++;
        continue;
      }
      
      if(hYen > 0){
        cnt += Bis;
        hYen--;
        continue;
      }else if(i == num-1){
          cnt++;
          continue;
      }else if(cnt >= Yen){
          cnt -= Yen;
          hYen++;
      }else{
          cnt++;
      }
    }
  }
  
  cout << cnt << endl;
}