#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

const long long MOD = 1000000007;

int main(){
  string s;
  cin>>s;
  if(s=="keyence") {
    std::cout << "YES" << std::endl;
    return 0;
  }
  for(int i=0; i<s.size(); i++) {
    for(int j=1; i+j<s.size(); j++) {
      string t = s;
      t.erase(i,j);
      if(t == "keyence") {
	std::cout << "YES" << std::endl;
	return 0;
      }
    }
  }
  std::cout << "NO" << std::endl;
  return 0;
}
