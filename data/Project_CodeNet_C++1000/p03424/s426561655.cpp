#include<bits/stdc++.h>
using namespace std;

int main(){
  int n = 0;
  cin >> n;
  int i;
  for (i = 0; i < n;i++){
    string s;
    cin >> s;
    if (s =="Y"){
      cout << "Four" << endl;
      break;
    }
  }
  if (i == n) cout << "Three" << endl;
}
