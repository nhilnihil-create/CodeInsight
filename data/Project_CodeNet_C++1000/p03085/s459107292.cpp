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
  char c;
  cin >> c;
  char res;
  if(c == 'A')res = 'T';
  if(c == 'T')res = 'A';
  if(c == 'C')res = 'G';
  if(c == 'G')res = 'C';
  cout << res << endl;
}