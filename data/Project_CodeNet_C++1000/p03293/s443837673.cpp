#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

#define DEBUG if(false)

using namespace std;

int main(){

  string S, T;
  cin >> S;
  cin >> T;
  bool boolean;
  int len = S.length();
  for(int i = 0; i < len; i++){
    boolean = true;
    for(int j = 0; j < len; j++){
      if(S[j] != T[(i+j)%len]){
        boolean = false;
        break;
      }
    }
    if(boolean){
      break;
    }
  }
  if(boolean){
    printf("Yes\n");
  }else{
    printf("No\n");
  }

  return 0;
}
