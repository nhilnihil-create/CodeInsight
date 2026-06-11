#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  if(S=="KIHBR" || S=="AKIHBR" || S=="KIHABR" || S=="KIHBAR" ||
     S=="KIHBRA" || S=="AKIHABR" || S=="AKIHBAR" || S=="AKIHBRA" ||
     S=="KIHABAR" || S=="KIHABRA" || S=="KIHBARA" || S=="AKIHABAR" ||
     S=="AKIHABRa" || S=="AKIHBARA" || S=="KIHABARA" || S=="AKIHABARA"){
    cout << "YES" << endl;
  }
  
  else{
    cout << "NO" << endl;
  }
  
}
  
  