#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool x =false;

  for (int i =0; i<N; i++){
    string op;
    cin >> op;
    if (op=="Y"){
      x = 1;
      break;
    }

  }
  if (x==true)
  cout<<"Four"<<endl;
  else
    cout<<"Three"<<endl;
  
}
