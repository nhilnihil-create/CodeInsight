#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  string s;
  ll k;
  cin >> s >> k;
  int i = 0;
  int res = 0;
  res = 1;
  while(1){
    if(s[i] != '1'){
      res = s[i] - '0';
      break;
    }
    i++;
  }
  if(k < i + 1)cout << 1 << endl;
  else cout << res << endl;
}