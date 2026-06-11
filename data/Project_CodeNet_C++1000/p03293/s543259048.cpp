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
  string s,t;
  cin >> s >> t;
  bool res = false;
  if(s == t)res = true;
  for(int i = 0;i < s.size() - 1;i++){
    string now;
    now = s.substr(i + 1,s.size() - i + 1) + s.substr(0,i + 1);
    //cout << now << endl;
    if(t == now)res = true;
  }
  if(res)cout << "Yes" << endl;
  else cout << "No" << endl;
}