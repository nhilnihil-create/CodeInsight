#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  string t = "AKIHABARA";
  cin >> s;
  
  if (s.size() > t.size()) { 
    cout << "NO\n";
  }else if (s == t) {
    cout << "YES\n";
  }else {
    if (s.size() == 5) {
      if (s == "KIHBR") {
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }
    }else if (s.size() == 6) {
      if (s == "AKIHBR" || s == "KIHABR" || s == "KIHBAR" || s == "KIHBRA") {
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }
    }else if(s.size() == 7) {
      if (s == "AKIHABR" || s == "AKIHBAR" || s == "AKIHBRA" || s == "KIHABAR" || s == "KIHABRA" || s == "KIHBARA") {
        cout << "YES\n";
      }else {
        cout << "NO\n";
      }
    }else {
      if(s == "AKIHABAR" || s == "AKIHBARA" || s == "KIHABARA") {
        cout << "YES\n";
      }else {
        cout << "NO\n";
      }
    }
  }
}