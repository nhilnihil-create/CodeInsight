#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int x1,x2,y1,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int x3 = y1 - y2 + x2;
  int y3 = y2 + x2 - x1;
  int x4 = x1 - x2 + x3;
  int y4 = y1 - y2 + y3;
  cout << x3 << " " << y3 << " " << x4 << " " <<  y4 << endl;
}
