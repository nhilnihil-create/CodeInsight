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
  ll a,b;
  cin >> a >> b;
  if(max(a,b) <= 8)cout << "Yay!" << endl;
  else cout << ":(" << endl;
}