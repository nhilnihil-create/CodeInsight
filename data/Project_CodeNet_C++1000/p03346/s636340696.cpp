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
  int n = 0;
  cin >> n;
  int res = 0;
  vector<int> m(n);
  for(int i = 0;i < n;i++){
    cin >> m[i];
    m[i]--;
  }
  vector<int> a(n);
  for(int i = 0;i < n;i++){
    a[m[i]] = i;
  }
  int now = 0;
  now = 1;
  for(int i = 0;i < n - 1;i++){
    if(a[i] < a[i + 1]){
      now++;
    }
    else{
      now = 1;
    }
    res = max(res,now);
  }
  res = max(res,now);
  cout << n - res << endl;
}