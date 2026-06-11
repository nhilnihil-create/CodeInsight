#include <bits/stdc++.h>
using namespace std;

int main() {
  int num;
  int tmp1, tmp2;
  int cnt = 0;
  cin >> num;
  
  vector<int> vec(num);
  for(int i = 0; i < num; i++) cin >> vec.at(i);
  
  while(true){
    if(*max_element(vec.begin(), vec.end()) == 0) break;
    
    int i = 0;
    while(i < num){
      if(vec.at(i) == 0){
        i++;
      }else{
        cnt++;
        while(i < num && vec.at(i) > 0){
          vec.at(i)--;
          i++;
        }
      }
    }
  }
  
  cout << cnt;
}
