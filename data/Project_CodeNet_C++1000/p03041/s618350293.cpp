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
  ll n,k;
  string s;
  cin >> n >> k >> s;
  s[k - 1] = (s[k - 1] - 'A') + 'a';
  cout << s << endl;
}