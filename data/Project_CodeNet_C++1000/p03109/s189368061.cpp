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
  ll y = 0;
  y = stoll(s.substr(0,4));
  ll m = 0;
  m = stoll(s.substr(5,2));
  if((y == 2019 && m >= 5) || y >= 2020)cout << "TBD" << endl;
  else cout << "Heisei" << endl; 
}