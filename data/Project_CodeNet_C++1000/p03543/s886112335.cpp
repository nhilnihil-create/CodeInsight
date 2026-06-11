#include <bits/stdc++.h>
using namespace std;

int main(){
  int x = 0;
  string N;
  cin >> N;
  for(int i = 0; i < (int(N.size()) - 1); i++){
    if (N[i] == N[i+1]){
      x++;
      if(x == 2){
        cout << "Yes" << endl;
        break;
      }
    }
    else {
      x = 0;
    }
  }
  if(x < 2){
    cout << "No" << endl;
  }
}