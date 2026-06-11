#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

  bool yellow = false;

  char color;
  for(int i = 0; i < N; i++){
    cin >> color;
    if(color == 'Y'){
      yellow = true;
      break;
    }
  }
  if(yellow){
    cout << "Four" << endl;
  }
  else{
    cout << "Three" << endl;
  }
}
