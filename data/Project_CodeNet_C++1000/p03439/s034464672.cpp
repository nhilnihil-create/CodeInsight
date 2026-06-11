#include <iostream>
#include <string>
using namespace std;
string s, t;

int main() {
  int N; cin >> N;
  cout << 0 << endl;
  cin >> s;
  if(s == "Vacant") {
    return 0;
  }
  int l = 0, r = N;
  while(t != "Vacant") {
    int mid = (l+r) / 2;
    cout << mid << endl;
    cin >> t;
    if(mid % 2^s == t) l = mid;
    else r = mid;
  }
  return 0;
}
