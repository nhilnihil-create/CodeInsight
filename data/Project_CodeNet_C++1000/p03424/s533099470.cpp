#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, count = 3;
  cin >> N;
  for(int i = 0; i < N; i++){
    char S;
    cin >> S;
    if(S == 'Y'){
      count += 1;
      break;
    }
  }
  if(count == 3){
    cout << "Three" << endl;
  }
  else{
    cout << "Four" << endl;
  }
}
