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
  vector<int> p(5); 
  int k;
  rep(i,5) cin >> p[i];
  cin >> k;

  for(int i = 0; i<4; ++i) for(int j = i+1; j<5; ++j){
    if(p[j]-p[i]>k) {
      cout << ":(" << endl;
      return 0;
    }
  }
  cout << "Yay!" << endl;
}
