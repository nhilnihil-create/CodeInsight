#include <bits/stdc++.h>
using namespace std;

int main() {
  int d,g;
  cin >> d >> g;
  
  using pii = pair<int,int>;
  vector<pii> v;
  for (int i=0; i<d; i++) {
    int p,c;
    cin >> p >> c;
    v.push_back(pii(p,c));
  }
  
  int mincnt = 10000;
  for (int i=0; i<(1<<d); i++) {
    bitset<10> b = i;
    int count = 0;
    int sum = 0;
    for (int j=0; j<d; j++) {
      if (b.test(j)) {
        sum += 100*(j+1)*v.at(j).first + v.at(j).second;
        count += v.at(j).first;
      }
    }
    int index;
    for (int j=d-1;j>=0;j--) {
      if (!b.test(j)) {
        index = j;
        break;
      }
    }
    for (int j=0; j<=v.at(index).first; j++) {
      if (j!= v.at(index).first) {
        if (sum + 100*(index+1)*j >= g) {
          count += j;
          mincnt = min(mincnt, count);
          break;
        }
      } else {
        if (sum + 100*(index+1)*j + v.at(index).second >= g) {
          count += j;
          mincnt = min(mincnt, count);
          break;
        }
      }
    }
  }
  cout << mincnt << endl;
  
}
