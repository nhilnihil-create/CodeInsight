#include <bits/stdc++.h>
using namespace std;

int main() {
  int M = 0;
  cin >> M;
  if(M<0 || M>24){
    cout << "error" << endl;
    return -1;
  }
  cout << 48-M << endl;
}
