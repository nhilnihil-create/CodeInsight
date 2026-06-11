#include <iostream>
#include <string>
using namespace std;
int main(void){
  int i;
  string s,sa[16]={"KIHBR","AKIHBR","KIHABR","AKIHABR","KIHBAR","AKIHBAR","KIHABAR",
                   "AKIHABAR","KIHBRA","AKIHBRA","KIHABRA","AKIHABRA","KIHBARA",
                   "AKIHBARA","KIHABARA","AKIHABARA"};
  cin >> s;
  for (i=0;i<16;i++) if (s==sa[i]) break;
  if (i==16) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}