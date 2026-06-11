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
  ll c = 0;
  for(int i = 0;i < (int)s.size();i++){
    c += s[i] - '0';
  }
  c = min(c,(ll)s.size() - c);
  cout << c * 2 << endl;
}