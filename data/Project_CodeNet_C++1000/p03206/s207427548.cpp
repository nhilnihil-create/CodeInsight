#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
using ll = long long;
using P = pair<int,int>;

int main(void) {
  int D;
  cin >> D;

  if(D==25) {
    cout << "Christmas" << endl;
  } else if(D==24) {
    cout << "Christmas Eve" << endl;
  } else if(D==23) {
    cout << "Christmas Eve Eve" << endl;
  } else if(D==22){
    cout << "Christmas Eve Eve Eve" << endl;
  }
  return 0;
}
