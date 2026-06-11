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
  ll res = 0;
  for(int i = 0;i < (int)s.size();i++)if(s[i] == '+')res++;
  res = res + -1 * (s.size() - res);
  cout << res << endl;
}