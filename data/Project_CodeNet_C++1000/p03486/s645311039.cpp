#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[]) {
  string s,t;
  std::cin >> s>>t;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  reverse(t.begin(),t.end());
  if (s<t) {
    std::cout << "Yes" << '\n';/* code */
  }
  else{
    std::cout << "No" << '\n';
  }
  return 0;
}
