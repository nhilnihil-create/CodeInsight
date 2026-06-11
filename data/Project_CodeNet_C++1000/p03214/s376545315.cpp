#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void){
  float n;
  cin >> n;
  
  float sum = 0;
  
  vector<float>a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum += a[i];
  }
  
  sum /= n;
  float max = 100000000;
  int ans = 0;
  for(int i=0;i<n;i++){
    if(max > abs(sum - a[i])){
      ans = i;
      max = abs(sum - a[i]);
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
