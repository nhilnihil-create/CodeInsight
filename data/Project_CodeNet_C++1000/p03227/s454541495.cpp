#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  if(s.size() == 3){
    swap(s.at(0), s.at(2));
    cout << s << endl;
  }
  else
    cout << s << endl;
}
