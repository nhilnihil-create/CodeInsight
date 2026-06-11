#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, count=0;
  string s;
  bool Pink=1,White=1,Green=1,Yellow=1;
  
  cin >> n;
  while(n>0){
    cin >> s;
    if(s == "P" && Pink == 1){
      count += 1;
      Pink = 0;
    }else if(s == "W" && White == 1){
      count += 1;
      White = 0;
    }else if(s == "G" && Green == 1){
      count += 1;
      Green = 0;
    }else if (s == "Y" && Yellow == 1){
      count += 1;
      Yellow = 0;
    }else if(count == 4){
      break;
    }
    
    n --;
  }
  
  if(count == 3){
    cout << "Three" <<endl;
  }else if(count == 4){
    cout << "Four" << endl;
  }
}