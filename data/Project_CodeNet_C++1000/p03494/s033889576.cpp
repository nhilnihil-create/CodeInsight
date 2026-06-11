#include <bits/stdc++.h>
using namespace std;

int main(){
  int num;
  cin >> num;
  int cnt = 100000000000000000000;
  int now_num;
  for(int i = 0; i < num; i++){
    cin >> now_num;
    int count = 0;
    while(true){
      if(now_num % 2 == 0){
        now_num /= 2;
        count += 1;
      }
      else{
        break;
      }
    }
    if(count < cnt){
      cnt = count;
    }
  }
  cout << cnt << endl;
}