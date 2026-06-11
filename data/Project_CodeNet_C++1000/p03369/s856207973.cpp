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
  ll res = 700;
  for(int i = 0;i < 3;i++){
    if(s[i] == 'o')res += 100;
  }
  cout << res << endl;
}