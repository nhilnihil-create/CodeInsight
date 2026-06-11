#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  vector<string> a = {"AKIHABARA", "AKIHABAR", "AKIHABRA", "AKIHBARA", "KIHABARA",
                      "AKIHABR", "AKIHBAR", "AKIHBRA", "KIHABAR", "KIHBAR", "KIHABRA",
                      "AKIHBR", "KIHABR", "KIHBAR", "KIHBRA", "KIHBR"};
  for(int i = 0; i < 16; i++){
    if(s == a[i]) {cout << "YES" << endl; return 0;}
  }
  cout << "NO" << endl;
  return 0;
}