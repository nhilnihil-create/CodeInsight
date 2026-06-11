#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void){
  int n,a,b;
  cin >> n >> a >> b;
  
  vector<int>p(n);
  for(int i=0;i<n;i++){
    cin >> p[i];
    if(p[i] <= a) p[i] = 1;
    else if(p[i] <= b) p[i] = 2;
    else p[i] = 3;
  }
  
  int s = 0;
  int t = 0;
  int u = 0;
  
  for(int i=0;i<n;i++){
    if(p[i] == 1) s++;
    if(p[i] == 2) t++;
    if(p[i] == 3) u++;
  }
  
  cout << min(min(s,t),u) << endl;
  
  return 0;
}
