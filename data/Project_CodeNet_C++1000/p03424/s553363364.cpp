#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string result = "Three";
  string color;
  
  cin >> N;
  
  for (int i = 0; i < N; i ++){
    cin >> color;
    if (color == "Y"){
      result = "Four";
      break;
    }
  }
  
  cout << result << endl;
}
