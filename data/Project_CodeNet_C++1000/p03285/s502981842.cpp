#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool answer = false;
  
  for(int i=0; i <= N/4; i++) {
    for(int j=0; j <= N/7; j++) {
     if(4*i + 7*j == N) answer = true;
    }
  }
  if(answer == true)  cout << "Yes" << endl;
  else cout << "No" << endl;
}