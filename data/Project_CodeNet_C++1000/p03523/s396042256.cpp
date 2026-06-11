#include<iostream>
using namespace std;
int main(){
  string s; cin >> s;
  string v[] = {"AKIHABARA",
                "KIHABARA",
                "AKIHBARA",
                "AKIHABRA",
                "AKIHABAR",
                "KIHBARA",
                "KIHABRA",
                "KIHABAR",
                "AKIHBRA",
                "AKIHBAR",
                "AKIHABR",
                "KIHBRA",
                "KIHBAR",
                "KIHABR",
                "AKIHBR",
                "KIHBR"
               };
  bool f = false;
  for(int i = 0; i < 16; ++i)f |= s == v[i];
  cout << (f ? "YES" : "NO") << endl;
}