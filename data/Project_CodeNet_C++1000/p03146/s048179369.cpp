#include <bits/stdc++.h>
using namespace std;

int main(){
  int s;
  cin >> s;
  int nt = s;
  vector<int> v(1, s);
  for (int i = 2; true; i++){
    if (nt % 2 == 0) nt /= 2;
    else nt = 3 * nt + 1;
    for (int j = 0; j < v.size(); j++){
      if (nt == v.at(j)){
        cout << i << endl;
        return 0;
      }
    }
    v.push_back(nt);
  }
}