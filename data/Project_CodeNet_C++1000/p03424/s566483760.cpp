#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string c;
  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> c;
    
    if(c == "Y"){
      cout << "Four" << endl;
      return 0;
    }
  }
    cout << "Three" << endl;
    return 0;
}
