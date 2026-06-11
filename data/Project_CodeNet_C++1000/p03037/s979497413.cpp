#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>

// int max: 2 x 10^9, long long max: 9 x 10^18

using namespace std;

const int MOD = 1000000007;

int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> l(m), r(m);
  
  for(int i=0; i<m; i++){
    cin >> l[i] >> r[i];
  }
  
  int lowwer = *max_element(l.begin(), l.end());
  int upper = *min_element(r.begin(), r.end());
  
  int result = upper - lowwer + 1;
  if(result < 0){
    cout << 0;
  }else{
    cout << result;
  }
  
  return 0;
}