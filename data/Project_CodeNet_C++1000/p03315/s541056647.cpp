#include <bits/stdc++.h>
using namespace std;

int main(){
  char c;
  int res = 0;
  for(int i = 0; i < 4; i++){
    cin >> c;
    if(c == '-') res--;
    else res++;
  }
  cout << res << '\n';
}
