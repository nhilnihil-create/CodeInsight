#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int a = 0;
  string s;
  cin >> N;
  
  
  for (int i = 0; i < N; i++){
    cin >> s;
    if (s == "Y"){
      a = 1;
    }
  }
    
  if (a == 1){
    cout << "Four" << endl;
  }
  if (a == 0){
     cout << "Three" << endl;
  }
}