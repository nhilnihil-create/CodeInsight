#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  int N;
  cin >> N;
  vector<char> hina(N);
  for(int i =0;i<N;i++){
    cin >> hina.at(i);
  }
  bool Y=false;
  
  for(int i = 0;i<N;i++){
    if(hina.at(i)=='Y'){
      Y=true;
      break;
    }
  }
  if(Y){
    cout << "Four" << endl;
  }else{
    cout << "Three" << endl;
  }
}
