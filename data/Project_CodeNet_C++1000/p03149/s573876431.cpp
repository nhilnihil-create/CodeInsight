#include <bits/stdc++.h>
using namespace std;

int main(){
  int N[4];
  int cnt_1=0, cnt_7=0, cnt_9=0, cnt_4=0;
  for(int i=0; i<4; i++) cin >> N[i];
  for(int j=0; j<4; j++){
    if(N[j]==1) cnt_1++;
    if(N[j]==7) cnt_7++;
    if(N[j]==9) cnt_9++;
    if(N[j]==4) cnt_4++;
  }
  if(cnt_1==1 && cnt_7==1 && cnt_9==1 && cnt_4==1){
    cout << "YES";
  }else{
    cout << "NO";
  }
  return 0;
}