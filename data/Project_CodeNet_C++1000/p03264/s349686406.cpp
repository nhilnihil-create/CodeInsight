#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

  int Neven= N/2;
  int Nodd= N- Neven;

  int ans= Neven* Nodd;

  cout << ans << endl;
}