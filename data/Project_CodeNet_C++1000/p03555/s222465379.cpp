#include <bits/stdc++.h>

using namespace std;


int main()
{
  string s,t;
  cin >> s >> t;
  int j = 2;
  for(int i = 0;i < 3;i++){
    if(s.at(i) != t.at(j)) {
      cout << "NO";
      return 0;
    }
    j--;
  }
  cout << "YES";

}
