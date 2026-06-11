#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i*4<=n; ++i){
    if((n-i*4)%7==0){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
