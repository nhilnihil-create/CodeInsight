#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, up, down;
  cin >> N;
  up = N/10;
  down = N-(N/1000)*1000;
  if(up%111 == 0 || down%111 == 0)cout << "Yes" << endl;
  else if(up == 0 || down == 0)cout << "Yes" << endl;
  else{cout << "No" << endl;}
}