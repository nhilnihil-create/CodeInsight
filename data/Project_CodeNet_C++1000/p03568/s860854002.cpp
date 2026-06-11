#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> a.at(i);
    if (a.at(i) % 2 == 1){
      b.at(i) = 1;
    }
    else{
      b.at(i) = 2;
    }    
  }
  int x = 1;
  for (int i = 0; i < n; i++){
    x *= b.at(i);
  }
  
  cout << pow(3, n) - x << endl;
}