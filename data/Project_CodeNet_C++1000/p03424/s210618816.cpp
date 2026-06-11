#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int X = 3;
  for (int i=0;i<N;i++){
    string S;
    cin >> S;
    if (S=="Y"){
      X++;
      break;
    }
  }
  if (X==3){
    cout <<"Three"<<endl;
  }
  else {
    cout<<"Four"<<endl;
  }
}
