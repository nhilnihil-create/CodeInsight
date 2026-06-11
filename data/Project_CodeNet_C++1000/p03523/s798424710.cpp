#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    if(S == "AKIHABARA" || S == "AKIHABAR" || S == "AKIHABRA" ||
       S == "AKIHBARA" || S == "KIHABARA" || S == "AKIHABR" ||
       S == "AKIHBAR" || S == "KIHABAR" || S == "AKIHBRA" ||
       S == "KIHABRA" || S == "KIHBARA" || S == "KIHBRA" ||
       S == "KIHBAR" || S == "KIHABR" || S == "AKIHBR" ||
       S == "KIHBR") {
      cout << "YES" << endl;
      return 0;
    }
   cout << "NO" << endl;
}

