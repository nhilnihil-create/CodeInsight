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
  int n,a,b;
  cin >> n >> a >> b;
  vector<int> m(n);
  for(int i = 0;i < n;i++)cin >> m[i];
  int x,y,z;
  x = 0;
  y = 0;
  z = 0;
  for(int i = 0;i < n;i++){
    if(m[i] <= a)x++;
    else if(m[i] >= b + 1)z++;
    else y++;
  }
  cout << min({x,y,z}) << endl;
}