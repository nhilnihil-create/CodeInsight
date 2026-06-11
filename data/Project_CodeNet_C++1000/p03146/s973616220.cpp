#include <iostream>
#include <set>

using namespace std;

int main() {
  int s;
  cin >> s;

  set<int> as;

  as.insert(s);

  int i{1};
  while(1) {
    ++i;
    if (s%2) {
      s = 3*s+1;
    } else {
      s /= 2;
    }

    if(!as.insert(s).second) break;
  }

  cout << i << endl;
  
  return 0;
}
