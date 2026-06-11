#include <bits/stdc++.h>
using namespace std;

int main() {
  long long s,yon=0;
  cin >> s;
  if(s == 1 || s == 2 || s == 4){
    cout << 4 << endl;
    return 0;
  }
  int i=0;
  while(s != 4){
    if(s%2 == 0){
      s /= 2;
    }
    else{
     s = s*3+1;
    }
    i++;
  }
  cout << i+4 << endl;
}
