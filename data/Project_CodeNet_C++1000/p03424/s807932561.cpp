#include <bits/stdc++.h>
using namespace std;

int main() { int N;
  cin >> N;
  vector<string> v(N);

  int f = 0;
  for (int i = 0; i < N; i++) {
    cin >> v.at(i);
    if(v.at(i) =="Y"){
      f = 1;
      break;
    }
  }
  if(f==1){
    cout << "Four" << endl;
  }else{
    cout << "Three" << endl;
  }
}