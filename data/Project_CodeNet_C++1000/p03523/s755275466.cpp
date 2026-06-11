#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  if(s == "KIHBR" || s == "KIHBRA" || s == "KIHBAR" || s == "KIHBARA" || s == "KIHABR" || s == "KIHABRA" || s == "KIHABARA" || s == "AKIHBR" || s == "AKIHBRA" || s == "AKIHBAR" || s == "AKIHBARA" || s == "AKIHABR" || s == "AKIHABRA" || s == "AKIHABAR" || s == "AKIHABARA" || s == "KIHABAR"){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
	return 0;
}
