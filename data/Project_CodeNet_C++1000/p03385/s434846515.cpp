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
  if(s[0] != s[1] && s[1] != s[2] && s[2] != s[0])cout << "Yes" << endl;
  else cout << "No" << endl;
}