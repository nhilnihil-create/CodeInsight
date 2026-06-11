#include<bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  int size = s.size();
  int64_t sint = stoll(s);
  int64_t tenpros = 10;
  for(int i = 0; i < size - 4; i++) {
    tenpros *= 10;
  }
  vector<int> spartint(size - 2);
  for(int i = 0; i < size-2; i++) {
    spartint.at(i) = sint / tenpros;
    sint -= sint / (tenpros * 100) * (tenpros * 100);
    tenpros /= 10;
  }
  vector<int> differencebetween753(size - 2);
  for(int i = 0; i < size -2; i++) {
    if(spartint.at(i) <= 753) {
      differencebetween753.at(i) = 753 - spartint.at(i);
    }
    else {
      differencebetween753.at(i) = spartint.at(i) - 753;
    }
  }
  sort(differencebetween753.begin(), differencebetween753.end());
  cout << differencebetween753.at(0) << endl;
}