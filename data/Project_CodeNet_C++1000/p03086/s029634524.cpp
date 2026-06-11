#include<bits/stdc++.h>
using namespace std;
int main() {
  string str; cin >> str;
  int size = str.size();
  vector<bool> acgt(size, 0);
  for(int i = 0; i < size; i++) {
    if(str.at(i) == 'A' || str.at(i) == 'C' || str.at(i) == 'G' || str.at(i) == 'T') {
      acgt.at(i) = 1;
    }
  }
  int seen = 0, maxkari = 0, maxnum = 0;
  bool exist1 = 0;
  while(seen < size) {
    if(acgt.at(seen) == 0) {
      maxnum = max(maxnum, maxkari);
      maxkari = 0;
      exist1 = 1;
    }
    else {
      maxkari++;
    }
    seen++;
  }
  maxnum = max(maxnum, maxkari);
  cout << maxnum << endl;
}