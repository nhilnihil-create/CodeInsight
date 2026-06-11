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
  ll n = 0;
  string s;
  cin >> n >> s;
  ll all = 0;
  for(int i = 0;i < s.size();i++){
    if(s[i] == '#')all++;
  }
  ll now = 0;
  ll res = 0;
  res = max(res,all);
  for(int i = 0;i < n;i++){
    if(s[i] == '.')now++;
    else all--;
    res = max(res,now + all);
  }
  res = max(res,now);
  cout << s.size() - res << endl;
  return 0;
}