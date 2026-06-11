#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)


int main(){
  int x1,x2,y1,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int dv[] = {x2 - x1,y2 -y1};
  cout << x2 - dv[1] << " " << y2 + dv[0] << " " 
       << x2 - dv[1] - dv[0] << " " << y2 + dv[0] - dv[1] << endl;  




  return 0; 
}

