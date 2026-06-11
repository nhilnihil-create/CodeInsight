#include <bits/stdc++.h>
using namespace std;
int main () {
  string S, A = "AKIHABARA", sub;
  string data[16] = {"AKIHABARA", "AKIHABAR", "AKIHABRA", "AKIHABR", "AKIHBARA", "AKIHBAR", "AKIHBRA", "AKIHBR", "KIHABARA", "KIHABAR", "KIHABRA", "KIHABR", "KIHBARA", "KIHBAR", "KIHBRA", "KIHBR"};
  cin >> S;
  for(int i = 0; i < 16; i++){
    if(S == data[i]){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}