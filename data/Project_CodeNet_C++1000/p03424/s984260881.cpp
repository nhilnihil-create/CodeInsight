#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string search = "";
  cin >> N;
  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    if (search.find(s) == string::npos){
      search+=s;
    }
  }
  if (search.size()==3){
   cout << "Three" << endl;
  }
  else{
   cout << "Four" << endl;
  }
 
}