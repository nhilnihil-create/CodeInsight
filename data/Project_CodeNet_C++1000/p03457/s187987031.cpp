#include <bits/stdc++.h>
using namespace std;

int main() {
  int num;
  int nowX = 0;
  int nowY = 0;
  int tmp1,tmp2,tmp3,tmptCnt;
  int tCnt,tX,tY;
  bool chk = true;
  
  cin >> num;
  
  for(int i = 0; i < num; i++){
    cin >> tCnt >> tX >> tY;
    tmp1 = abs(nowX - tX);
    tmp2 = abs(nowY - tY);
    tmp3 = tmp1 + tmp2;
    tmptCnt = tCnt - tmptCnt;
    
    if(tmp3 > tmptCnt){
      // timeout
      chk = false;
      break;
    }
    
    if(tmptCnt % 2 == 0){
      if(tmp3 % 2 == 0){
        nowX = tX;
        nowY = tY;
        tmptCnt = tCnt;
      }else{
        chk = false;
        break;
      }
    }else{
      if(tmp3 % 2 == 1){
        nowX = tX;
        nowY = tY;
        tmptCnt = tCnt;
      }else{
        chk = false;
        break;
      }
    }
  }
  if(chk == true) cout << "Yes";
  else cout << "No";
}
