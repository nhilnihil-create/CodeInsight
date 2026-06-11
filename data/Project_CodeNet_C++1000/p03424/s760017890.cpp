#include <bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  bool b[4];
  
  char c;
  for(int i = 0 ; i < N ; i++){
    cin >> c;
    if (c == 'G'){
      b[0] = 1;
    }else if(c == 'W'){
      b[1] = 1;
    }else if(c == 'Y'){
      b[2] = 1;
    }else if(c == 'P'){
      b[3] = 1;
    }
  }

  int ans = 0;
  for(int i = 0 ; i < 4 ; i++){
    if(b[i] == 1){
      ans++;
    }
  }

  switch(ans){
  case 3:
    cout << "Three" << endl;
    break;
  case 4:
    cout << "Four" << endl;
  }

}
