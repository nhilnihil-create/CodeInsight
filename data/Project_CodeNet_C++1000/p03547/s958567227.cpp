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
  string a,b;
  cin >> a >> b;
  if(a > b)cout << ">" << endl;
  else if(a < b)cout << "<" << endl;
  else cout << "=" << endl;
}