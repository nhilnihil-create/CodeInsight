#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  string s;
  cin >> s;
  int x,y;
  cin >> x >> y;
  vector<int> canMoveX(16001,0);
  vector<int> canMoveY(16001,0);
  bool mukiX=true;
  int susumu=0,now=0;
  for(susumu=0;1;susumu++){
    now++;
    if(s[now-1]=='T'){
      break;
    }else if(now==s.length()){
      susumu++;
      break;
    }
  }
  mukiX=false;
  canMoveX[susumu+8000]=1;
  canMoveY[8000]=1;
  if(now==s.length()){
    if(canMoveX[x+8000]&&canMoveY[y+8000]){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
    return 0;
  }
  while(1){
    for(susumu=0;1;susumu++){
      now++;
      if(s[now-1]=='T'){
        break;
      }else if(now==s.length()){
        susumu++;
        break;
      }
    }
    if(mukiX){
      for(int i=0;i<16001;i++){
        if(canMoveX[i]&1){
          canMoveX[i-susumu]|=2;
          canMoveX[i+susumu]|=2;
        }
      }
      for(int i=0;i<16001;i++){
        canMoveX[i]/=2;
      }
    }else{
      for(int i=0;i<16001;i++){
        if(canMoveY[i]&1){
          canMoveY[i-susumu]|=2;
          canMoveY[i+susumu]|=2;
        }
      }
      for(int i=0;i<16001;i++){
        canMoveY[i]/=2;
      }
    }
    mukiX=(!mukiX);
    if(now==s.length()){
      if(canMoveX[x+8000]&&canMoveY[y+8000]){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
      return 0;
    }
  }
  return 0;
}
