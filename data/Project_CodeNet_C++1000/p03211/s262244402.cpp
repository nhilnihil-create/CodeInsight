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
  cin >> s;
  int res = 0;
  res = pow(10,9);
  for(int i = 0;i < s.size() - 2;i++){
    string t;
    t = s.substr(i,3);
    //cout << t << endl;
    int now = 0;
    now = stoi(t);
    res = min(res,abs(753 - now));
  }
  cout << res << endl;
}